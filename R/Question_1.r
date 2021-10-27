func <- function(x, sigma) #function which contains the value of the given function f(x)
{
  mew = 0
  a = 1/(((2*pi)^0.5)*sigma) * exp(-((x-mew)^2)/(2*sigma*sigma))
} 

x = seq(-100,100,0.05) #Defines the points for x and range of x-axis
plot(x,
     func(x, 1),
     main = "Graph for Function with different sigma values",
     type = "l",
     col = "red",
     sub = "Question 1",
     xlab = "",
     ylab = "")
lines(x, func(x,3), col = "blue") 
lines(x, func(x,7), col = "pink")
lines(x, func(x,55), col = "green") #makes remaining 3 lines for the graph
legend("topleft",
       c("Sigma = 1", "Sigma = 3", "Sigma = 7", "Sigma = 55"),
       fill = c("red", "blue", "pink", "green")) #makes the legend
