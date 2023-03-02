i=1
while [ $i -lt 21 ]
do
	touch file$i.txt
	((i++))
done

