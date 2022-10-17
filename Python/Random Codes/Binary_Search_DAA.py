import timeit
import matplotlib.pyplot as m

def binary_search(arr, l, r, k):
    while(l<=r):
        mid=l+(r-l)//2
        if arr[mid] == k:
            return mid
        elif arr[mid] < k:
            l = mid + 1
        else:
            r = mid - 1
    return -1

#We assume that the input array is sorted in ascending order
n = int(input("Enter the number of elements of array: "))
arr = list(map(int, input("Enter the elemenets in a single line: "). split()))
k = int(input("Enter the key to be found: "))
ret = binary_search(arr, 0, n, k)
if ret==-1:
    print("Key Not Found!")
else:
    print("Key found at ", ret)

t = []
val=[]
#For n = 1000 to 100000, considering all cases
x = range(1000, 100000, 250)
for i in x:
    for j in range(i):
        val.append(j)
    #Calculates Time for each time loop run
    start = timeit.default_timer()
    #It checks for the worst case scenario
    binary_search(val, 0, i, -1)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("Binary Search of N")
m.ylabel("Time")
m.plot(x, t, 'o')
m.show()
