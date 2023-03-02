echo -n "Enter the radius of circle: "
read r

pi=3.14

area=`echo $r \* $r \* $pi|bc`
c=`echo 2 \* $r \* $pi|bc`
echo "Area is $area and Circumference is $c"
