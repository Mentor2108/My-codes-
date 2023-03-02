echo -n "Enter a number: "
read n

if [ $n -le 1 ]
then
	echo "The number is not a prime number."
	exit 0
fi

if [ `expr $n % 2 ` == 0 ]
then
	echo "The number is not a prime number."
	exit 0
fi

i=3
x=`echo "sqrt($n)" | bc`
while [ $i -le $x ]
do
	if [ `expr $n % $i` == 0 ]
	then
		echo "The number is not a prime number."
		exit 0
	fi
	((i+=2))
done

echo "The number is a prime number."


