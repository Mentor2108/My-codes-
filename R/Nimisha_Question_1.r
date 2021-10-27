mew = 0
sigma = 1
a = 1/(((2*pi)^0.5)*sigma) * exp(-((x-mew)^2)/(2*sigma*sigma))

x = seq(-10,10,0.05) #Defines x
plot(x, a,
     main = "Graph",
     type = "l",
     col = "pink",)
sigma = 3
a = 1/(((2*pi)^0.5)*sigma) * exp(-((x-mew)^2)/(2*sigma*sigma))
lines(x, a, col = "red") #Makes 
sigma = 7
a = 1/(((2*pi)^0.5)*sigma) * exp(-((x-mew)^2)/(2*sigma*sigma))
lines(x, a, col = "black")
sigma = 55
a = 1/(((2*pi)^0.5)*sigma) * exp(-((x-mew)^2)/(2*sigma*sigma))
lines(x, a, col = "blue") 
legend("topleft",
       c("Sigma: 1", "Sigma: 3", "Sigma: 7", "Sigma: 55"),
       fill = c("pink", "red", "black", "blue")) #makes the legend

