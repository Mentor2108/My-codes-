import timeit
import matplotlib.pyplot as m
import random

def partition(array, low, high):
    pivot = array[high]
    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1
  
def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)

n = int(input("Enter the number of elements of array: "))
arr = list(map(int, input("Enter the elemenets in a single line: "). split()))

quick_sort(arr, 0, n-1)
print(arr)
t = []
val=[]

#For n = 5 to 50000, considering all cases

x = range(5000, 50000, 5000)
for i in x:
    #Generates Random Numbers
    val=random.sample(range(0, 10000000), i)
    #Calculates Time for each time loop run for Average Case (Random Numbers)
    start = timeit.default_timer()
    quick_sort(val, 0, i-1)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("Quick sort for array of size N")
m.ylabel("Time in Seconds")
m.plot(x, t, '-o')
m.show()
