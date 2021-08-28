# wrong approach, try later
t = int(input())
while t:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in b:
        a.append(i)
    a.sort()
    l = len(a)
    x = -1
    a.append(x)
    for i in range(0 ,l):
        if (a[i] == a[i+1]):
            continue
        if (a[i]%3==0):
            print(a[i], end = " ")
    t-=1
