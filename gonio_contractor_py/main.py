from codac2 import *


class CtcMultiBearing(Ctc):

  def __init__(self, m_, y_):
    Ctc.__init__(self, 3)
    self.m = m_
    self.y = y_

  def contract(self, x):
    n = len(self.m)
    A = IntervalMatrix(n,2)
    b = IntervalVector(n)
    p = IntervalVector([x[0],x[1]])
    
    for i in range(0,n):
      A[i,0] = sin(x[2]+self.y[i])
      A[i,1] = -cos(x[2]+self.y[i])
      b[i] = self.m[i][0]*sin(x[2]+self.y[i])-self.m[i][1]*cos(x[2]+self.y[i])
    

    MulOp.bwd(b,A,p)
    x.put(0,p)
    return x


# State vector
x = Vector([-3,-2,PI/4.])

# Landmarks
m = [
  IntervalVector([0,6]), IntervalVector([4,0])#, IntervalVector([3,7])
]

# x2=IntervalVector(Interval(-10,10),Interval(-10,10))
# prin
# Bearing measurements
y = []
for mi in m:
  y.append((atan2((mi[1]-x[1]),(mi[0]-x[0]))-x[2]).inflate(0.05))
  mi.inflate(0.05)

x2= IntervalVector([Interval(-10,10),Interval(-10,10)])

x3= IntervalVector([Interval(-10,10),Interval(-10,10),Interval(PI/4)])

print(x2)

print("m",m)
print("y",y)
# Le CtcMultiBearing contracteur permet une estimation de l'état (3d)
# On cherche à paver (visualiser) les solutions pour les positions (x1,x2)
# #Donc on réalise une projection : ici, cap est supposé complètement inconnu (theta \in [-pi,pi])

c = CtcProj(CtcMultiBearing(m, y), [0,1], [Interval(PI/4)])
draw_while_paving([[-10,10],[-10,10]], c, 0.1)
# x2=c.contract(x2.subvector(0,1))
# x2=print("x",x2)

# c=CtcMultiBearing(m,y)
# x3=c.contract(x3)

# print("X3",x3)



# for mi in m:
#   DefaultView.draw_box(mi, [Color.black(),Color.white()])
# for yi in y:
#   DefaultView.draw_pie(x.subvector(0,1), [0,999], yi+x[2])
# DefaultView.draw_tank(x, 0.7, [Color.black(),Color.yellow(0.5)])