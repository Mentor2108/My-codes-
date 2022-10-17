import timeit
import matplotlib.pyplot as m
import random
 
def JobScheduling(n, arr, t=3):
    # Sort all jobs according to
    # decreasing order of profit
    arr.sort(key = lambda x: (x[2]), reverse = True)

    result = [False] * t 
    job = ['-1'] * t
    for i in range(len(arr)):
        for j in range(min(t - 1, arr[i][1] - 1), -1, -1):
            if result[j] is False:
                result[j] = True
                job[j] = arr[i][0]
                break
    return job

n = int(input("Enter the number of Jobs: "))
p = list(map(int, input("Enter the starting time of each job in a single line: "). split()))
q = list(map(int, input("Enter the finishing time of each job in a single line: ").split()))

#The array contains Job id, start time and finish time
arr = [[i+1, p[i],q[i]] for i in range(n)]

print(JobScheduling(n, arr))
t = []
val=[]

#For n = 5000 to 100000, considering all cases
#We will take w as random as well
x = range(5000, 100000, 5000)
for i in x:
    #Generates Random Numbers
    for j in range(i):
        val.append([j+1, random.randint(0,50000),random.randint(0, 50000)])
    #Calculates Time for each time loop run for Average Case (Random Numbers)
    start = timeit.default_timer()
    JobScheduling(i, val)
    stop = timeit.default_timer()
    val = []
    t.append(stop-start)

#Draws the Graph
m.xlabel("Job Scheduling for array of size N")
m.ylabel("Time in Seconds")
m.plot(x, t, '-o')
m.show()
