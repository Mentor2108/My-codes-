gcd <- function(x, y) #finds GCD 
{
  while(y)
  {
    ans = y
    y = x%%y
    x = ans
  }
  return(x)
}
func <- function(n) #Returns the Vector with all the numbers
{
  num = 1:n
  i <- 2
  ans <- 1
  if (n == 1 | n == 2)
  {
    return(ans)
  }
  repeat
  {
    if (gcd(num[i], n) == 1)
    {
      ans <- append(ans, num[i])
    }
    i = i + 1
    if (i == n)
    {
      break
    }
  }
  return(ans)
}
print(length(func(2))) #Prints length of vector
print(length(func(5)))
print(length(func(100))) 
