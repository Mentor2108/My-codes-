#! /bin/bash

#OS Lab 4


if [ $# -eq 0 ] #If there are no arguments
then
	echo "Model Name               : "`grep "model name" -m 1 /proc/cpuinfo | cut -d " " -f 3-`
	#Searches in the file for the first occurence of 'model name' and cuts the output fancily
	echo "Kernel Version           : "`uname -r`
	#Gives the kernel Version
	echo "Total Memory             : "`grep "MemTotal" -m 1 /proc/meminfo | rev | cut -d " " -f 1-2 | rev`
	#Tells the memory of the Computer (Cut is used to print output fancily)
	echo "System uptime since boot : "`cut -d " " -f 1 /proc/uptime` "seconds"
	#The First number is the uptime in seconds
	exit 0
fi

#We assume that the printout_rate is a multiple of read_rate (So we can calculate average)

if [ $(($2%$1)) -ne 0 ]
then
	echo "Printout rate Should be a multiple of Read rate."
	exit 1
fi


#Initialising Variables for use to calculate average
user_perc=0
sys_perc=0
idle_perc=0
avail_mem_perc=0
sectors_read_total=0
sectors_written_total=0
switches_total=0
processes_total=0

#Number of samples whose average is printed per output
sample=$(echo $2/$1 | bc -l)
i=$1 #Timer (In seconds)

#Calculating Initial Values
total_time_s=$(grep "cpu" -m 1 /proc/stat | cut -c 5-) #Calculates CPU time of all types
user_mode_s=`echo $total_time_s | cut -d " " -f 1-2 --output-delimiter "+" | bc -l` #Gets Processes in User mode
sys_mode_s=`echo $total_time_s | cut -d " " -f 3` #Gets Processes in System/Kernel Mode
idle_mode_s=`echo $total_time_s | cut -d " " -f 4` #Gets Processes in Idle Mode
total_time_s=$((${total_time_s// /+})) #Adds all the CPU Times


#I have in my laptop nvme0n1 and sda both, but most computers have sda, so I will use sda here
sectors_read_s=$(grep "sda" -m 1 /proc/diskstats| awk '{printf $6}')
sectors_written_s=$(grep "sda" -m 1 /proc/diskstats| awk '{printf $10}')
switches_s=$(grep "ctxt" -m 1 /proc/stat | cut -d " " -f 2)
processes_s=$(grep "processes" -m 1 /proc/stat | cut -d " " -f 2)


while true
do

	#Sleeps for the reading time
	echo -e "Please wait $1 seconds...\nReading data..."
	sleep $1

	#Reading CPU Stats Again...
	total_time=$(grep "cpu" -m 1 /proc/stat | cut -c 5-)
        user_mode=`echo $total_time | cut -d " " -f 1-2 --output-delimiter "+" | bc -l`
        sys_mode=`echo $total_time | cut -d " " -f 3`
        idle_mode=`echo $total_time | cut -d " " -f 4`
        total_time=$((${total_time// /+}))

        #Reading Diskstats, context switches and processes
        sectors_read=$(grep "sda" -m 1 /proc/diskstats| awk '{print $6}')
        sectors_written=$(grep "sda" -m 1 /proc/diskstats| awk '{print $10}')
        switches=$(grep "ctxt" -m 1 /proc/stat | cut -d " " -f 2)
        processes=$(grep "processes" -m 1 /proc/stat | cut -d " " -f 2)

	#Reading Memory Info
	total_mem=$(awk 'NR==1 {print $2}' /proc/meminfo)
	available_mem=$(awk 'NR==3 {print $2}' /proc/meminfo)


	#Calculating the change in each value after "read-interval" time
	total_time_change=$(($total_time-$total_time_s))
	user_mode_change=$(($user_mode-$user_mode_s))
	sys_mode_change=$(($sys_mode-$sys_mode_s))
	idle_mode_change=$(($idle_mode-$idle_mode_s))

	sectors_read_total=$(($sectors_read_total+$sectors_read-$sectors_read_s))
	sectors_written_total=$(($sectors_written_read+$sectors_written-$sectors_written_s))

	switches_total=$(($switches_total+$switches-$switches_s))
	processes_total=$(($processes_total+$processes-$processes_s))


	#Calculating Percentage
	user_perc=$(echo $user_mode_change/$total_time_change*100+$user_perc | bc -l)
	sys_perc=$(echo $sys_mode_change/$total_time_change*100+$sys_perc | bc -l)
	idle_perc=$(echo $idle_mode_change/$total_time_change*100+$idle_perc | bc -l)

	avail_mem_perc=$(echo $available_mem/$total_mem*100+$avail_mem_perc | bc -l)

	#Resetting Start Times
	total_time_s=$total_time
	user_mode_s=$user_mode
	sys_mode_s=$sys_mode
	idle_mode_s=$idle_mode
	sectors_read_s=$sectors_read
	sectors_written_s=$sectors_written
	switches_s=$switches
	processes_s=$processes

	if [ $i -eq $2 ]
	then
		i=0

		#Printing Output
		echo -------------------------------------------------------------------------------------------
		echo "Percentage Of CPU in User Mode          : "`echo $user_perc/$sample | bc -l`%
		echo "Percentage Of CPU in System/Kernel Mode : "`echo $sys_perc/$sample | bc -l`%
		echo "Percentage Of CPU in Idle Mode          : "`echo $idle_perc/$sample | bc -l`%
		echo "Amount of Memory Available              : $available_mem kB"
		echo "Percentage Of Memory Available          : "`echo $avail_mem_perc/$sample | bc -l`%
		echo "Sectors read per second                 : "`echo $sectors_read_total/$sample | bc -l`
		echo "Sectors written per second              : "`echo $sectors_written_total/$sample | bc -l`
		echo "Context switches per second             : "`echo $switches_total/$sample | bc -l`
		echo "Processes Created per second            : "`echo $processes_total/$sample | bc -l`
		echo -------------------------------------------------------------------------------------------


		#Resetting values to find next average
		user_perc=0
		sys_perc=0
		idle_perc=0
		available_mem_perc=0
		sectors_read_total=0
		sectors_written_total=0
		switches_total=0
		processes_total=0

	fi

	i=$(($i+$1))
done

