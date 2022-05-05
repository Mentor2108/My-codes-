n = int(input())
a = sorted(list(map(int, input().split())))
for i in range(1, n+1):
    if (i==n):
        print(i)
        exit()
    if (i!=a[i-1]):
        print(i)
        exit()

