echo -n "Enter first line of input: "
read n
echo -n "Enter the number of Processes: "
read np

for ((i=0; i<$np; i++))
do

	echo -n "Enter arrival time: "
	read arrival_time[$i]

done

for ((i=0; i<$np; i++))
do
	echo -n "Enter burst time: "
	read burst_time[$i]
done

for ((i=0; i<$np; i++))
do
        echo -n "${burst_time[$i]} "
done

