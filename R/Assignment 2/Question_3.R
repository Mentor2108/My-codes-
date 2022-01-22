#Necessary Libraries
library(graphics)
library(pbivnorm)

#Initializing Vectors with values I randomly chose
x <- seq(-5, 3, length.out = 35)
y <- seq(-6, 5, length.out = 35)

#Function for using "outer"
func <-function(x,y)
{
  pbivnorm(x,y)
}

z<-outer(x,y, FUN = func)

#Making graph
persp(x, y, z,
      theta = -45,
      phi = 35, 
      main = "Joint CDF Of Bivariate Normal Distribution",
      xlab = "X",
      ylab = "Y",
      zlab = "Z",
      col = "pink",
      shade = 0.69,
      ltheta = -45,
      lphi = 30)
