#!/bin/bash
# Monitoring script for Born2beroot project #

# Helper functions #

## Percentage function ##

ft_ram_usage()
{
	ram_usage=$(($1 * 100))
	ram_usage="$(echo $ram_usage / $2 | bc -l | sed -E 's/([0-9]+\.[0-9]{1,2})[^ ]*/\1/g')"
}

## Disk Usage function ##

ft_disk_usage()
{
	disk_usage=$(($1 * 100))
	disk_usage="$(echo "$disk_usage / $2" | bc -l | sed -E 's/([0-9]+\.[0-9]{1,2})[^ ]*/\1/g')"
}

## Disk Space conv function ##

ft_disk()
{
	total_disk="$(echo "$total_disk / 1000000" | bc -l | sed -E 's/([0-9]+\.[0-9]{1,2})[^ ]*/\1/g')"
	total_disk=$total_disk"Gb"
	available_disk="$(echo "$available_disk / 1000000" | bc -l | sed -E 's/([0-9]+\.[0-9]{1,2})[^ ]*/\1/g')"
	available_disk=$available_disk"G"
	used_disk="$(echo "$used_disk / 1000000" | bc -l | sed -E 's/([0-9]+\.[0-9]{1,2})[^ ]*/\1/g')"
	used_disk=$used_disk
}

ft_lvm_status()
{
	if [ $1 != 0 ]
	then
		lvm_status="yes"
	else
		lvm_status="no"
	fi
}

# Getting all the needed values #

architecture="$(uname -snrmov)"
p_processors="$(grep '^core id' /proc/cpuinfo | uniq | wc -l)"
v_processors="$(nproc --all)"
total_ram="$(free -m | grep Mem | awk -F ' ' '{print $2}')"
used_ram="$(free -m | grep Mem | awk -F ' ' '{print $3}')"
available_ram="$(free -m | grep Mem | awk -F ' ' '{print $NF}')"
total_disk="$(df | awk -F ' ' '{print $2}' | tail -n +2 | tr '\n' '+' | rev | cut -c2- | rev | bc -l)"
used_disk="$(df | awk -F ' ' '{print $3}' | tail -n +2 | tr '\n' '+' | rev | cut -c2- | rev | bc -l)"
available_disk="$(df | awk -F ' ' '{print $4}' | tail -n +2 | tr '\n' '+' | rev | cut -c2- | rev | bc -l)"
#cpu_load="$(mpstat | tail -n 1 | awk '{print $6+$4 "%"}')"
last_reboot="$(who -b | awk '{print $3" "$4}')"
#SET LVM STATUS
lvm_status="available"
#lvm_status="$(lsblk | grep LVM | wc -l)"
#tcp_connections="$(netstat | grep ESTABLISHED | wc -l)"
users_logged="$(w | tail -n+3 | wc -l)"
#ip_address="$(ip addr | grep "inet " | head -1 | awk '{print $2}')"
#mac_address="$(ip addr | grep ether | awk '{print $2}'
#nbr_sudo="$(grep sudo /var/log/auth.log | grep COMMAND | wc -l)"

# Calling the helper functions to get the remaining values #
ft_ram_usage $used_ram $total_ram
ft_disk_usage $used_disk $total_disk
ft_disk
ft_lvm_status $lvm_status

# Setting the name of the file that will be used to print the message #
msg_file="/tmp/message"

# Creation of the file that will be used by the wall command #
touch $msg_file

# Printing of the values into the file what will be used by the wall command #
echo "#Architecture: $architecture" > $msg_file
echo "#CPU physical : $p_processors" >> $msg_file
echo "#vCPU: $v_processors" >> $msg_file
total_ram=$total_ram"Mb"
echo "#Memory Usage : $used_ram/$total_ram ($ram_usage%)" >> $msg_file
echo "#Disk Usage : $used_disk/$total_disk ($disk_usage%)" >> $msg_file
echo "#CPU load : $cpu_load" >> $msg_file
echo "#Last boot : $last_reboot" >> $msg_file
echo "#LVM use : $lvm_status" >> $msg_file
echo "#Connections TCP : $tcp_connections ESTABLISHED" >> $msg_file
echo "#User log : $users_logged" >> $msg_file
echo "#Network : IP $ip_address ($mac_address)" >> $msg_file
echo "#Sudo : $nbr_sudo cmd" >> $msg_file

# Printing of the message to the users of the computer #
wall $msg_file

# Deletion of the file that was used by the wall command #
shred --iterations=10 -u $msg_file
