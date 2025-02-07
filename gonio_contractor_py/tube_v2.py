import codac as c1
import codac2 as c2
import math
from vibes import vibes
import numpy as np
import interface_codac as Interface


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

x=c1.TubeVector(tdomain,dt,3)
v=c1.TubeVector(tdomain,dt,3)
u=c1.Tube(u_truth, dt)


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

t = 10 # detection time
x_t = x_truth(t)

M = [
    c1.IntervalVector((0,6)),
    c1.IntervalVector((4,0)),
    ]
# angle measurement at a time t
y = [] 
for mi in M:
    # Compute bearing measurement and inflate by 0.05
    angle = math.atan2(mi[1].mid() - x_t[1], mi[0].mid() - x_t[0]) - x_t[2]
    y.append(c1.Interval(angle).inflate(0.005))
    mi.inflate(0.05)



# print("y",y)
# print("M",M)

ctc_deriv = c1.CtcDeriv()
ctc_eval=c1.CtcEval()
ctc_gonio=Ctc_gonio(M,y)




c1.beginDrawing()

fig_map = c1.VIBesFigMap("Map")
fig_map.set_properties(100,100,500,500)
fig_map.axis_limits(-20,25,-10,15)
fig_map.add_trajectory(x_truth, "x", 0, 1)
fig_map.add_tube(x, "x", 0, 1)
fig_map.show(1)

# for m in M:
#   fig_map.add_beacon(m.inflate(0.1), "red")

cn= c1.ContractorNetwork()


# p = cn.create_interm_var(c1.IntervalVector(3,(-c1.oo,c1.oo)))
p = c1.IntervalVector(3)


cn.add(ctc_eval, [t,p, x, v])  # Évaluation de la trajectoire à t
cn.add(ctc_gonio, [p])


cn.add(ctc_deriv, [x, v])  # Contrainte entre position et vitesse


cn.contract()




fig_map.show(1)

vibes.endDrawing()


'''

il faut creer un contractor gonio pour chaque landmark.
ou bien un contracteur gonio pour tout les landmarks

'''