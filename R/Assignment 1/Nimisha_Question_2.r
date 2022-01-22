hcf <- function(x, y) { 
  if(x > y) {
    smaller = y
  } else {
    smaller = x
  }
  for(i in 1:smaller) {
    if((x %% i == 0) && (y %% i == 0)) {
      hcf = i
    }
  }
  return(hcf)
} #Find HCF
func <- function(n) #Returns the length
{
  num = 1:n
  i <- 2
  ans <- 1
  if (n == 2 | n == 1)
  {
    return(ans)
  }
  while(i!=n)
  {
    if (gcd(num[i], n) == 1)
    {
      answer <- append(answer, num[i])
    }
    i = i + 1
  }
  return(length(ans))
}
print(func(2)) #Prints answer
print(func(5))
print(func(100)) 
