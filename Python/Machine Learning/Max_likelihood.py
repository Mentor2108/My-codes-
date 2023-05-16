import matplotlib.pyplot as plt
import numpy as np

data = np.array([27, 64, 3, 18, 8]) 

lambda_array = np.geomspace(0.01, 0.1, 100)
LL = []
for L in lambda_array:
    loglik = np.log(L)-L*data
    LL.append(loglik.sum())

plt.plot(lambda_array, LL)
plt.xlabel('$\lambda$')
plt.ylabel('Log-likelihood')
plt.title('Log likelihood over a range of $\lambda$ values')
plt.show()