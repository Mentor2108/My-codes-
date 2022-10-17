import timeit
import matplotlib.pyplot as m
import random

#We can define a class to combine the weights and prices of each element for ease 
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight 

def fractionalKnapsack(W, arr):
    #Sorts the Array on basis of value wrt their weight in Descending Order
    arr.sort(key=lambda x: (x.value/x.weight), reverse=True) 
    finalvalue = 0.0

    for item in arr:
        if item.weight <= W:
            W -= item.weight
            finalvalue += item.value
        else:
            finalvalue += item.value * W / item.weight
            break
    return finalvalue

W = int(input("Enter the maximum weight of the Knapsack: "))
n = int(input("Enter the number of Items: "))
v = list(map(int, input("Enter the values of each item in a single line: "). split()))
wt = list(map(int, input("Enter the values of each weight in a single line: ").split()))

#Arranges them together (We cannot directly print the array)
arr = [Item(v[i], wt[i]) for i in range(n)]

max_val = fractionalKnapsack(W, arr)
print(max_val)
t = []
val=[]

#Weight can't be 0 

#For n = 5000 to 800000, considering all cases
#We will take w as random as well
x = range(5000, 800000, 5000)
for i in x:
    #Generates Random Numbers
    temp = random.randint(100, 1000) #Random W
    for j in range(i):
        val.append(Item(random.randint(1000,50000),random.randint(1000, 50000)))
    #Calculates Time for each time loop run for Average Case (Random Numbers)
    start = timeit.default_timer()
    fractionalKnapsack(temp, val)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("Fractional Knapsack for array of size N")
m.ylabel("Time in Seconds")
m.plot(x, t, '-o')
m.show()
