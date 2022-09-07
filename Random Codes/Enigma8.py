from math import factorial

n = int(input())
n+=1
print("total routes:", int(factorial(2*n - 2)/factorial(n-1)**2))