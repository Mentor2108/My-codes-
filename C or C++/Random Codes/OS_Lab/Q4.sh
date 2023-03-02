echo -n "Enter an year: "
read n

if [ `expr $n % 4` == 0 ]
then
if [ `expr $n % 100` == 0 ]
then 
if [ `expr $n % 400` == 0 ]
then
echo "This is a leap year."
else
echo "This is not a leap year."
fi
else
echo "This is a leap year."
fi
else
echo "This is not a leap year."
fi


