t = int(input())
while(t>0):
    fac = 1
    n = int(input())
    for i in range (2,n+1):
        fac*=i
    print(fac)
    t-=1