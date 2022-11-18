from numpy import exp

k = 55
r = 0.01
u = 1.5
d = 0.7
T = 5
s0 = 50

dt = T/365
rate = 1/(exp(r*dt)) #Shortcut for 1/1+r = 1/(1 - 1 + e^r*dt)

p = (rate-d)/(u-d)
q = 1-p
n = [30, 60, 90]
s = [[s0]]

for i in range(T):
    temp = [0]*(2**(i+1))
    x = 0
    for j in s[i]:
        curr = j
        temp[x] = curr*u
        x+=1
        temp[x] = curr*d
        x+=1
    s.append(temp)
print(s)
# v = [0]*(T+1)
# for i in range(T+1):
#     v[i] = s[i].copy()

# for i in range(2**T):
#     v[-1][i] = max(s[-1][i]-k, 0)
# for i in range(T-1, -1, -1):
#     for j in range(2**i):
#         v[i][j] = (v[i+1][2*j]*p + v[i+1][2*j + 1]*q)*rate
# print(v)