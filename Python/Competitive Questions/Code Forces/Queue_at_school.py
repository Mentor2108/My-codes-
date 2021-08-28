n,t = map(int,input().split())
a = list(input())
while (t>0):
    i=0
    while(i<n-1):
        if (a[i] == "B" and a[i+1] == "G"):
            a[i] = "G"
            a[i+1] = "B"
            i+=2
        else:
            i+=1
    t-=1  
print(a)


""" 
n,t = map(int,input().split())
a = list(input())
while (t>0):
    i=0
    for i in range (n-1):
        if (a[i] == "B" and a[i+1] == "G"):
            a[i] = "G"
            a[i+1] = "B"
            i+=1
    t-=1  
print(a)
 """