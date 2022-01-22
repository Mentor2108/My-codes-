#Necessary Libraries
library(pracma)

#Making function whose integration is to be found
FuncForIntegration <- function(x, y, z)
{
  5*x - 3*y
}

#Since ymax and zmax are not constant, we need a function for them
ymax <- function(x) 
{
  1 - x
}

zmax <- function(x, y) 
{
  1 - x - y
}

#Rest of the constants
xmin <- 0
xmax <- 1
ymin <- 0
zmin <- 0

#Final Integral
integral3(FuncForIntegration, xmin, xmax, ymin, ymax, zmin, zmax)
