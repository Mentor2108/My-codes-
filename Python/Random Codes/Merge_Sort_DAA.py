import timeit
import matplotlib.pyplot as m
import random

def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]

        mergeSort(L)
        mergeSort(R)
 
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

n = int(input("Enter the number of elements of array: "))
arr = list(map(int, input("Enter the elemenets in a single line: "). split()))

mergeSort(arr)
#Printing Sorted Array

print(arr)
t = []
val=[]

#For n = 5000 to 50000

x = range(5000, 50000, 5000)
for i in x:
    #Generates Random Numbers of size i
    val=random.sample(range(0, 10000000), i)
    #Calculates Time for each time loop run for Average Case (Random Numbers)
    start = timeit.default_timer()
    mergeSort(val)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("Merge Sort of array of size N")
m.ylabel("Time in Seconds")
m.plot(x, t, "-o")
m.show()
