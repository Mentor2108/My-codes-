#Necessary Packages
library(stats)
library(ggplot2)

k <- seq(from = 1, to = 30) 
PDF_k <- dgeom(k-1, 1/41)
CDF_k <- pgeom(k-1, 1/41) 

#Making Data Frame
Question2_dist <- data.frame(k = k, Density = PDF_k, Distribution = CDF_k)


#Plotting PDF and CDF resp. using Bar graph
ggplot(Question2_dist, aes(x = k, y = Density)) +
  geom_bar(stat="identity",width = 0.69, fill = "#a497f7") +
  scale_x_continuous(breaks=k)

ggplot(Question2_dist, aes(x = k, y = Distribution)) +
  geom_bar(stat="identity",width = 0.69, fill = "#90eba4") +
  scale_x_continuous(breaks=k)

#Probability of P(X <= 101):
Ans <- 101

#Final Answer
print(pgeom(Ans-1, 1/41))
