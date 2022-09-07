# install.packages("SciViews")
R <-runif(900,min = 0,max = 1)
plot(R,
     main="Uniform random variable",
     xlab="Number of variables",
     ylab="Value of each variable",
     col="purple") #Random Uniformly Distributed Values 
library("SciViews")

x<-rep(0,900)

for (i in 1:900)
  x[i]<-(-1/3000)*ln(R[i]);
x<-cumsum
plot(x,
     main="exponential random variable",
     xlab="Number of variables",
     ylab="Value of each variable",
     col="blue")
