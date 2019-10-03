#!/bin/bash

dmesg | grep -C 2 cdc_
echo "--------------------------------------"
lsusb | grep Eric
echo "--------------------------------------"

# From
# http://www.thinkwiki.org/wiki/Ericsson_H5321_gw_Mobile_Broadband_Module#GPS

for n in `ls /sys/class/*/*{ACM,wdm}*/device/interface`
do
	echo $(echo $n|awk -F '/' '{print $5}') : $(cat $n)
done
