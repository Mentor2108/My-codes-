import timeit
import matplotlib.pyplot as m

def linear_search(x, k):
    for i in range(len(x)):
        if x[i]==k:
            print("Key found at position ", i)
            return 1
    return 0

n = int(input("Enter the number of elements of array: "))
arr = list(map(int, input("Enter the elemenets in a single line: "). split()))
k = int(input("Enter the key to be found: "))
if linear_search(arr, k)==0:
    print("Key Not Found!")

t = []
val=[]
#For n = 5 to 50000, considering all cases
x = range(5, 50000, 350)
for i in x: 
    for j in range(i):
        val.append(j)
    #Calculates Time for each time loop run
    start = timeit.default_timer()
    #It checks for the worst case scenario
    linear_search(val, -1)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("Linear Search of N")
m.ylabel("Time")
m.plot(x, t, 'o')
m.show()
