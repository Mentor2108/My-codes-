import timeit
import matplotlib.pyplot as m
import random

def knapSack(W, wt, val, n):
    dp = [0 for i in range(W+1)]  
    for i in range(1, n+1):  
        for w in range(W, 0, -1):
            if wt[i-1] <= w:
                dp[w] = max(dp[w], dp[w-wt[i-1]]+val[i-1])
 
    return dp[W]  

W = int(input("Enter the maximum weight of the Knapsack: "))
n = int(input("Enter the number of Items: "))
v = list(map(int, input("Enter the values of each item in a single line: "). split()))
wt = list(map(int, input("Enter the values of each weight in a single line: ").split()))


max_val = knapSack(W, wt, v, n)
print(max_val)
t = []
val=[]
wt = []
#Weight can't be 0 


#For n = 5000 to 800000, considering all cases
#We will take W as fixed value 500 because complexity is O(n*w) 
#This way we can directly see the relation between n and time
x = range(100, 1000, 100)
W = 500
for i in x:
    #Generates Random Numbers
    for j in range(i):
        wt.append(random.randint(1000,50000))
        val.append(random.randint(1000, 50000))
    #Calculates Time for each time loop run for Average Case (Random Numbers)
    start = timeit.default_timer()
    knapSack(W, wt, val, i)
    stop = timeit.default_timer()
    val = []
    wt = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("0-1 Knapsack for array of size N and weight 500")
m.ylabel("Time in Seconds")
m.plot(x, t, '-o')
m.show()
