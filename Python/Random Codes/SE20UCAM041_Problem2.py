S0=60  #initial stock price
K=65   #strike price
T=90   #time period in days
r=0.01 #risk-free rate 
# bin-period binomial model
UpFactor=1.5  #up - factor
DownFactor=0.7  #down-f
   
P = (1+r-DownFactor)/(UpFactor-DownFactor)
Q = 1-P     # Q = (1+r-DownFactor)/(UpFactor-DownFactor)
x =[30, 60, 90]

for N in x: 
    S = [[0 for i in range(N+1)] for j in range(N+1)] #Sn
    S[0][0]=S0 
    for i in range(1,N+1):
        for j in range(i+1):
            S[i][j] = S0 * UpFactor**j * DownFactor**(i-j)  #initial binomial tree
    # print(S)
    
    Gs = [[0 for i in range(N+1)] for j in range(N+1)] #Gs(n)
    for i in range(1,N+1):
        for j in range(i+1):
            Gs[i][j] = max(0,K-S[i][j])   #Calculating Gs(n)
    
    V = [[0 for i in range(N+1)] for j in range(N+1)] #Vn
    # print(Gs)

    for i in range(0, N+1):
        V[N][i] = Gs[N][i]
    
    for i in range(N-1, -1, -1):
        for j in range(i+1):
            V[i][j] = max(Gs[i][j], ((P*V[i+1][j]) + Q*V[i+1][j+1])/(1+r))
    
    delta = (V[1][0] - V[1][1])/(S[1][0] - S[1][1])
    
    print(f"Option Premium Price for N = {N}: {V[0][0]}")
    print(f"Delta for N = {N}: {delta}")
    

    


