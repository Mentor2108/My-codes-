t = int(input())
while(t):
    n = int(input())
    print("1")
    print("1*2")    
    for i in range(2,n):
        for j in range(0,i+1):
            print(j*'*', end = "")
            print(j+1, end = "")
        print()
    t-=1