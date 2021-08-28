n = int(input())
lx, ly,lz =[],[],[]

for i in range (n):
    x,y,z = input().split()
    lx.append(int(x))
    ly.append(int(y))
    lz.append(int(z))

if (sum(lx)==0 and sum(ly) == 0 and sum(lz) ==0):
    print("YES")
else:
    print("NO") 
