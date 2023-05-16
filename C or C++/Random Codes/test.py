def max_subarray_sum(A):
    n = len(A)
    max_ending_here = 0
    max_so_far = float('-inf')
    for i in range(n):
        max_ending_here = max(max_ending_here + A[i], A[i])
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

def solve(A):
    n = len(A)
    pre=[]
    i=0
    while i < len(A):
        if(i>=1):
            if(A[i]<0):
                break
        pre.append(A[i])
        if(len(A)-3==i):
            break
        i+=1
    post=[]
    B=A[i+1:len(A)]
    a=len(B)-1
    while a>=0:
        post.append(B[a])
        if(B[a-1]<=0):
            break
        if(a==len(B)-2):
            break
        a-=1
    C=A[i:i+a+1]
    r=max_subarray_sum(C)
    sume=r
    total=0
    for i in(A):
        sume+=i
    for a in range (len(B)):
        sume=sume+a
        # print(a)
    return sume-A[a]
        
    
    


A=[2,-3,-1,4]
print(solve(A))