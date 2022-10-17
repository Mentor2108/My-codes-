import timeit
import matplotlib.pyplot as m

def getMinMax(low, high, arr):
    arr_max = arr[low]
    arr_min = arr[low]
    if low == high:
        arr_max = arr[low]
        arr_min = arr[low]
        return (arr_max, arr_min)

    elif high == low + 1:
        if arr[low] > arr[high]:
            arr_max = arr[low]
            arr_min = arr[high]
        else:
            arr_max = arr[high]
            arr_min = arr[low]
        return (arr_max, arr_min)
    else:
        mid = int((low + high) / 2)
        arr_max1, arr_min1 = getMinMax(low, mid, arr)
        arr_max2, arr_min2 = getMinMax(mid + 1, high, arr)
 
    return (max(arr_max1, arr_max2), min(arr_min1, arr_min2))

n = int(input("Enter the number of elements of array: "))
arr = list(map(int, input("Enter the elemenets in a single line: "). split()))

Max, Min= getMinMax(0, n-1, arr)
print("The Max Element is ", Max)
print("The Min Element is ", Min)
t = []
val=[]

#For n = 1000 to 100000, considering all cases

x = range(1000, 100000, 1000)
for i in x:
    for j in range(i):
        val.append(j)
    #Calculates Time for each time loop run
    start = timeit.default_timer()
    getMinMax(0, i-1, val)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("MinMax of array of size N")
m.ylabel("Time")
m.plot(x, t, 'o')
m.show()
