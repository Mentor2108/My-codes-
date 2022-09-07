import timeit
import matplotlib.pyplot as m

def fact(n):
    if n == 0 or n==1:
        return 1
    if n==2:
        return 2
    return n*fact(n-1)

x = range(0, 21)
t = []
for i in x:
    start = timeit.default_timer()
    fact(i)
    stop = timeit.default_timer()
    t.append(stop-start)

m.xlabel("fact(n)")
m.ylabel("time")
m.plot(x, t, 'o')
m.show()
