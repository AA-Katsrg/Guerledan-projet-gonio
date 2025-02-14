import codac as c1
import codac2 as c2
import math
from vibes import vibes
import numpy as np
import interface_codac as Interface
import time

class CtcMultiBearing(c2.Ctc):

  def __init__(self, m_, y_):
    c2.Ctc.__init__(self, 3)
    self.m = m_
    self.y = y_

  def contract(self, x):
    n = len(self.m)
    A = c2.IntervalMatrix(n,2)
    b = c2.IntervalVector(n)
    p = c2.IntervalVector([x[0],x[1]])
    
    for i in range(0,n):
      A[i,0] = c2.sin(x[2]+self.y[i])
      A[i,1] = -c2.cos(x[2]+self.y[i])
      b[i] = self.m[i][0]*c2.sin(x[2]+self.y[i])-self.m[i][1]*c2.cos(x[2]+self.y[i])
      
    c2.MulOp.bwd(b,A,p)
    x.put(0,p)
    return x

class Ctc_gonio(c1.Ctc):

  def __init__(self, M_, y_):
    c1.Ctc.__init__(self, 3) # the contractor acts on 3d boxes
    self.m = M_  # Store the landmarks
    self.y = y_  # Store the bearings    # attribute needed later on for the contraction
    self.M2, self.y2 = self.c1_to_c2()
    self.ctc2 = CtcMultiBearing(self.M2, self.y2)

    print("M2",self.M2)
    print("y2",self.y2)

  def c1_to_c2(self):

    M2=[]
    for mi in self.m:
      m = Interface.convert_intervalVector_c1_to_c2(mi)
      M2.append(m)

    y2=[]
    for yi in self.y:
      y = Interface.convert_interval_c1_to_c2(yi)
      y2.append(y)

    return M2,y2

  def contract(self, x):
    
    x2= Interface.convert_intervalVector_c1_to_c2(x)
    x2 = self.ctc2.contract(x2)

    return Interface.convert_intervalVector_c2_to_c1(x2)




dt=0.01
tdomain= c1.Interval(0,15)


# Initial pose x0=(0,0,2)
x0 = (0,0,2)

# System input
u_truth = c1.Trajectory(tdomain, c1.TFunction("3*(sin(t)^2)+t/100"), dt)

# Actual trajectories (state + derivative)
v_truth = c1.TrajectoryVector(3)
x_truth = c1.TrajectoryVector(3)
v_truth[2] = u_truth
x_truth[2] = v_truth[2].primitive() + x0[2]
v_truth[0] = 10*c1.cos(x_truth[2])
v_truth[1] = 10*c1.sin(x_truth[2])
x_truth[0] = v_truth[0].primitive() + x0[0]
x_truth[1] = v_truth[1].primitive() + x0[1]

'''ce qui change ici qu'on utilise seulement 2 dimension'''
Xpsi=c1.Tube(tdomain,dt)
Xxy=c1.TubeVector(tdomain,dt,2)
v=c1.TubeVector(tdomain,dt,2)
u=c1.Tube(u_truth, dt)


# print("Xpsi",Xpsi)
# print("Xxy",u)
"""
mais ce qui ce suive dans une boucle 

print(x)
v[2] = u.inflate(0.03)
x[2] = c1.Tube(x_truth[2], dt)
#x[2].inflate(0.03)
v[0] = 10 * c1.cos(x[2])
v[1] = 10 * c1.sin(x[2])
v.inflate(0.1)
# x = v.primitive() + x0
x0_iv = c1.IntervalVector([x0[0], x0[1],x0[2]])  # Convert tuple to IntervalVector
x = v.primitive() + x0_iv
x[2] = c1.Tube(x_truth[2], dt)
"""


# t = 10 # detection time
# x_t = x_truth(t)

Xxy.set(x_truth(0.)[:2],0.)




# les differents balises que je veux remarquer a des temps differents
measurements = {
    10: c1.IntervalVector([-2, -7]),
    5: c1.IntervalVector([1, 15]), 
    # 8: c1.IntervalVector([14, 3]),
    12: c1.IntervalVector([5, -5]),
}

bearing_measurements = {}
for t, mi in measurements.items():
    x_t = x_truth(t)  # Get boat position at time t
    angle = math.atan2(mi[1].mid() - x_t[1], mi[0].mid() - x_t[0]) - x_t[2]
    bearing_measurements[t] = c1.Interval(angle)
    print("Bearing Measurements:", bearing_measurements[t])


c1.beginDrawing()

fig_map = c1.VIBesFigMap("Map")
fig_map.set_properties(100,100,500,500)
fig_map.axis_limits(-20,25,-10,15)
fig_map.add_trajectory(x_truth, "x", 0, 1)
fig_map.add_tube(Xxy, "x", 0, 1)
# fig_map.show(1)


# initialise le reseaux de contracteur
cn= c1.ContractorNetwork()
ctc_deriv = c1.CtcDeriv()
ctc_eval=c1.CtcEval()
cn.add(ctc_deriv, [Xxy, v])  # Contrainte entre position et vitesse


iteration_dt = 0.2 # elapsed animation time between each dt

# Create tubes defined over [t0,tf]
# Add already known constraints, such as motion equations

t = tdomain.lb()
prev_t_obs = t

bool=False

while t < tdomain.ub(): # run the simulation from t0 to tf
  t2=t
  t2 = round(t, 2) #parcque dt = 0.01 et on apres ajout ou division de 0.01 la valuer ajouter est en vrai presque 0.010000000001

  # Add the cn.add_data for x and v of the tube
  psit= c1.Interval(x_truth(t)[2])
  vt = c1.IntervalVector([c1.Interval(v_truth(t)[0]),c1.Interval(v_truth(t)[1])]).inflate(0)

  '''
   peut etre on aura un problem parcque le t est arrondie donc ca ne sera pas le vrai t dy tube
   peut etre ca ne sera pas un probleme parcque ci on change une partie a l'interieur 
  d'une tranche le cn.add_data contract tout seul sur tout la tranche
  '''

  cn.add_data(v, t,vt)
  cn.add_data(Xpsi, t, psit)
  # print(v(1))

  if t2 in measurements.keys():
    mi = measurements[t2]
    y = bearing_measurements[t2]
    print(f"[{t:.1f}s] Processing Landmark: {mi}, Bearing: {y}")

    # Apply observation constraints
    p = c1.IntervalVector(2)
    a = c1.Interval()

    # On peut ajouter de pecimisme sur mi et y avant que je les mais dans le contracteur
    ctc_gonio = Ctc_gonio([mi], [y])
    cn.add(ctc_eval, [c1.Interval(t), p, Xxy, v])  # Constrain position at t
    cn.add(ctc_eval, [c1.Interval(t), a, Xpsi])  # Constrain position at t
    cn.add(ctc_gonio, [p,a])  # Apply bearing constraint

    # Display detected landmark
    fig_map.add_beacon(mi, "red")
    prev_t_obs = t

  cn.contract()

  
  # contraction_dt = cn.contract_during(iteration_dt)
  # if iteration_dt>contraction_dt: # pause for the animation
  #   time.sleep(iteration_dt-contraction_dt) # iteration delay

  # Display the current slice [x](t)
  fig_map.draw_box(Xxy(t))

  t+=dt



fig_map.show(1)

vibes.endDrawing()
