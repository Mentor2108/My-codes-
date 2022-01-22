#Necessary Packages
library(graphics)
library(stats)

#I took 5000 so the graph looks smooth
x <- seq(from = -7.5, to = 7.5, length.out = 5000)

#Making Graph using plot with N(0,1)
plot(x, 
     dnorm(x, 0, 1),
     type = "l",
     lty = 1, 
     lwd = 2, 
     main = "PDF of t-distribution with N(0,1)",
     xlab = "X",
     ylab = "P(X)",
     col = "green")

#Adding Curves with different v
lines(x,dt(x, 1), type = "l", lty = 1, col = "cyan", lwd = 2)
lines(x,dt(x, 2), type = "l", lty = 1, col = "orange", lwd = 2)
lines(x,dt(x, 4), type = "l", lty = 1, col = "blue", lwd = 2)
lines(x,dt(x, 10), type = "l", lty = 1, col = "red", lwd = 2)
lines(x,dt(x, 69), type = "l", lty = 1, col = "purple", lwd = 2)

#Adding Legend
legend("topright",
       c("N(0,1)", "v = 1", "v = 2", "v = 4", "v = 10", "v = 69"),
       fill = c("green", "cyan", "orange", "blue", "red", "purple"))
