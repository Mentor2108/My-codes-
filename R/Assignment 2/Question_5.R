#Necessary Libraries 
library(stats)

x <- c(54, 63, 58, 72, 49, 92, 70, 73, 69, 104, 48, 66, 80, 64, 77) #Our Sample Space

n <- 15 #We know that size of our sample is 15
mew <- sum(x)/n
sigma <- sd(x) 
Vec <- c(1, -1) #Making a variable to make it easier to understand

Confidence <- function(percent, Size) #Function to avoid repetition
{
  return (mew + Vec*qt((1- percent/100)/2, Size - 1) * sigma/sqrt(Size))
}

#Final Answer
print(Confidence(90, n))

print(Confidence(95, n))
