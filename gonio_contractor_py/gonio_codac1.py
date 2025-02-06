import codac as c1
import codac2 as c2
from vibes import vibes
import math
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

    M2,y2= self.c1_to_c2()

    print("M2",M2)
    print("y2",y2)

    x2= Interface.convert_intervalVector_c1_to_c2(x)
    ctcc2 = CtcMultiBearing(M2, y2)
    x = Interface.convert_intervalVector_c1_to_c2(ctcc2.contract(x2))

    # # x2 = c2.CtcProj(c2.CtcMultiBearing(M2, y2), [0,1], [c2.Interval(c2.PI/4.)])
    # # c2.draw_while_paving([[-10,10],[-10,10]], x2, 0.1)
    # print(x2)
    # ctcc2 = c2.CtcProj(CtcMultiBearing(M2, y2), [0,1], [x2[2]])
    # # c2.draw_while_paving([[-10,10],[-10,10]], ctcc2, 0.1)

    # # ctc = c2.CtcProj(CtcMultiBearing(M2, y2), [0,1], [c2.PI/4])
    
    # x2_ = x2.subvector(0,1)
    # x2_=ctcc2.contract(x2_)

    # x.put(0,Interface.convert_intervalVector_c2_to_c1(x2_))
     
    return x



x_truth=(-3,-2,math.pi/4)

#landmakrs
M = [
    c1.IntervalVector((0,6)),
    c1.IntervalVector((4,0))
    ]


y = []  # List to store bearing intervals
for mi in M:
    # Compute bearing measurement and inflate by 0.05
    angle = math.atan2(mi[1].mid() - x_truth[1], mi[0].mid() - x_truth[0]) - x_truth[2]
    y.append(c1.Interval(angle).inflate(0.05))
    mi.inflate(0.05)


# Define the box to be contracted (x, y, theta)
x = c1.IntervalVector([c1.Interval(-10, 10), c1.Interval(-10, 10), c1.Interval(math.pi/4,math.pi/4)])

# Define the contractor
ctc_multi_bearing = Ctc_gonio(M, y)
# # ctc_multi_bearing.contract(x)
cn = c1.ContractorNetwork()

# Add contractors for each box
cn.add(ctc_multi_bearing, [x])

cn.contract()

print("x",x)

# print(x)

# ctc_gonio_proj = c1.CtcExist(ctc_multi_bearing,c1.IntervalVector(1,c1.Interval(math.pi/4,math.pi/4)),0.01)


# # Define some non-linear function
# f = c1.Function('x', 'y', 'x*cos(x-y)+y')

# # Build the separator associated to the constraint f(x,y) < 0
# sep = c1.CtcFunction(f, [-c1.oo,0])


# vibes.beginDrawing()
# c1.SIVIA([[-10,10],[-10,10]],ctc_gonio_proj,0.1)

