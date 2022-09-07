import matplotlib.pyplot as m
import numpy as np
import timeit

def gcd(a, b):
    if (b==0):
        return a
    else:
        return gcd(b, a%b)

# a, b = map(int, input().split())
x = range(40, 60)
y = range(40, 60)
z = []
t = []
for i in x:
    for j in y:
        start = timeit.default_timer()
        z.append(gcd(i,j))
        stop = timeit.default_timer()
        t.append(stop - start)
m.xlabel("gcd(a,b)")
m.ylabel("time")
m.plot(z, t, 'o')
m.show()


