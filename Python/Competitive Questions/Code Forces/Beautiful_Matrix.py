
a=[]
#inputting the 5x5 matrix 
for i in range (5):
    x = list(map(int, input().split()))
    a.insert(i, x)

count = 0 #number of moves

for i in range(5):
    for j in range (5):
        if (a[i][j]==1):
            r,c = i,j

count = abs(r-2) + abs(c-2)

print(count)