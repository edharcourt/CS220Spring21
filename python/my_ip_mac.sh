#!/bin/bash

exec >>/home/pi/cron.log 2>>/home/pi/cron.err.log

#set -x

export PATH=$PATH:/sbin

 #Get IP address of this pi
my_ip=`ifconfig wlan0 | grep -o -e "\<inet\> \([0-9]\+\.[0-9]\+\.[0-9]\+\.[0-9]\+\)" | cut -d' ' -f2`

# get mac address of this pi
my_mac=`ifconfig wlan0 | grep -o -e "\<ether\> \([a-f0-9]\+:[a-f0-9]\+:[a-f0-9]\+:[a-f0-9]\+:[a-f0-9]\+:[a-f0-9]\+\)" | cut -d' ' -f2`

# Use macaddress w/o ':'  for creating a unique filename
fnsfx=`echo $my_mac | sed 's/://g'`

fn=`echo ipmac_$fnsfx.txt`

# create a file ipmac_<macaddr>.txt
echo $my_ip,$my_mac,`date +%m,%d,%y,%H,%M,%S,%s` > ~/$fn

# copy file to ada
scp ~/$fn ed@ada.hpc.stlawu.edu:pi_ips/
ssh ed@ada.hpc.stlawu.edu "cat pi_ips/$fn >> pi_ips/ips.txt"
