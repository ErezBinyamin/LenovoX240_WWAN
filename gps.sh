#!/bin/bash
#SOURCES:
# http://www.thinkwiki.org/wiki/Ericsson_F3507g_Mobile_Broadband_Module#Using_the_card_as_a_GPS_receiver
# http://www.thinkwiki.org/wiki/Ericsson_H5321_gw_Mobile_Broadband_Module

#    X can be 0 (NMEA stream turned off) or 1 (NMEA stream turned on)
#    Y can be an integer form 1 to 60, and sets the frequency of how often the card emits the NMEA sentences
#    Z can be 0 (DGPS is turned off) or 1 (DGPS is turned on)

STREAM=1
FREQ=5
DGPS=1

#BROKEN ECHO DOES NOT WORK, USE SCREEN
#echo -e "AT*E2GPSCTL=$STREAM,$FREQ,$DGPS\r\n" >/dev/ttyACM1
#echo -e "AT*E2GPSNPD\r\n" >/dev/ttyACM2

# NMEA codes http://aprs.gids.nl/nmea/
# GPRMC is the "Recommended minimum specific GPS/Transit data"
# sudo cat /dev/ttyACM2 | grep -a GPRMC

# NUM SATELITES
#sudo cat /dev/ttyACM2 | grep -a GPGSA
#1    = Mode:
#       M=Manual, forced to operate in 2D or 3D
#       A=Automatic, 3D/2D
#2    = Mode:
#       1=Fix not available
#       2=2D
#       3=3D
#3-14 = IDs of SVs used in position fix (null for unused fields)
#15   = PDOP
#16   = HDOP
#17   = VDOP
#sudo cat /dev/ttyACM2 | grep -a GPGSA
