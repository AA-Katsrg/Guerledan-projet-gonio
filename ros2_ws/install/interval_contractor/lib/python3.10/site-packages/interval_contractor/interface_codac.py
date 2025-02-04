import codac as  c1
import codac2 as c2


'''conversion de codac 1 vers 2'''

def convert_interval_c1_to_c2(x):
    lower_bound= x.lb()
    uper_bound= x.ub()

    return c2.Interval(lower_bound,uper_bound)


def convert_intervalVector_c1_to_c2(V):
    n= V.size()
    V2= c2.IntervalVector(n)
    for i in range(n):
        V2[i]=convert_interval_c1_to_c2(V[i])
    
    return V2


'''conversion de codac 2 vers 1'''

def convert_interval_c2_to_c1(x2):
    lower_bound= x2.lb()
    uper_bound= x2.ub()

    return c1.Interval(lower_bound,uper_bound)


def convert_intervalVector_c2_to_c1(V2):
    n= V2.size()
    V= c1.IntervalVector(n)
    for i in range(n):
        V[i]=convert_interval_c2_to_c1(V2[i])
    
    return V

# V= c1.IntervalVector(3,(0,10))

# V= c1.IntervalVector([[3,4],[4,6]])


# V2= convert_intervalVector_c1_to_c2(V)

# V3=convert_intervalVector_c2_to_c1(V2)

# print("V2=",V2)

# print("V=",V)
# print("V3=",V3)


# v=c2.IntervalVector([[-10,10],[-10,10]])

# # print(v)
# V= c2.Interval(0,10)

# print("v=",V)

# V1= convert_interval_c2_to_c1(V)

# print("v1=",V1)


# v=c2.IntervalVector([[-10,10],[2,4]])
# v1=convert_intervalVector_c2_to_c1(v)

# print("v=",v)
# print("v1",v1)
