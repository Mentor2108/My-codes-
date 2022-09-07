gcd <- function(a, b) 
{
  if (b==0)
    return(a)
  else
    return(gcd(b, a%%b))
}
# a, b = map(int, input().split())

x = seq(0, 100, 0.5)
y = seq(0, 100, 0.5)
i= 0
while (i<length(x))
{
  j = 0
  while(j<length(y))
  {
    z = gcd(x,y)
    j = j+1
  }
  i=i+1
}
m.plot(x)
m.show()


