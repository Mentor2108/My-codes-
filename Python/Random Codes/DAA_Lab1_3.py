import timeit
import matplotlib.pyplot as m

def fibo(n):
    if n == 1 or n==2:
        return 1
    if n==3:
        return 2
    return fibo(n-1)+fibo(n-2)

x = range(1, 21)
t = []
for i in x:
    start = timeit.default_timer()
    fibo(i)
    stop = timeit.default_timer()
    t.append(stop-start)

m.xlabel("fibonacci(n)")
m.ylabel("time")
m.plot(x, t, 'o')
m.show()
