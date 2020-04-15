# Lenovo X240 WWAN

## Synopsis

Do you have a Lenovo X240? Did you buy a WWAN card for it? Want to mess around? This project is me doing that. I found out how to make the gps work.. That's kinda cool.

## Motivation

Ever since I was six years old I have always dreamed of communicating with my WWAN card over a serial connection and activating it's GPS module. Passion is a strange beast and one never knows exactly which passions will appear in which people. For me it was the Ericsson Business Mobile Networks BV WWAN card. I have fulfilled my childhood dream

## Installation and Requirements

1. Ericsson N5321 WWAN card
2. Computer that can connect to said WWAN card
3. Linux packages:
	- ```screen``` OR ```cu``` OR your favorite serial talky program
4. 

## Code

### 1. Print a bunnch of info
```bash
bash info.sh
```
You may see some output that looks like this:    
> ttyACM0 : N5321 gw Mobile Broadband Modem  
> ttyACM1 : N5321 gw Mobile Broadband Data Modem  
> ttyACM2 : N5321 gw Mobile Broadband GPS Port  
> cdc-wdm1 : N5321 gw Mobile Broadband Device Management  
> cdc-wdm2 : Ericsson N5321 gw  
> cdc-wdm3 : N5321 gw Mobile Broadband USIM Port  

We will be connecting to the **N5321 gw Mobile Broadband Data Modem** to configre the device and **N5321 gw Mobile Broadband GPS Port** to activate the GPS. Given my output that means I will first connect to ```/dev/ttyACM1``` and then ```/dev/ttyACM2```.

### 2. Configure GPS
Connect to the **N5321 gw Mobile Broadband Data Modem**
```
sudo screen /dev/ttyACM1
```
Configure the GPS Stream, frequency and DGPS.
```
AT
AT*E2GPSCTL=1,5,1
```
You may be unable to see your inputted text. When you hit enter the system should respond ```OK```

### 3. Activate GPS
Connect to the **N5321 gw Mobile Broadband GPS Port**
```
sudo screen /dev/ttyACM2
```
Activate the GPS module.
```
AT*E2GPSNPD
```
Hit enter and bam, boom. You got GPS data

### 4. Wait for satelites
May work best outdoors
```bash
sudo cat /dev/ttyACM2 | stdbuf -oL grep -a GPGSA | sed -u 's/\$GPGSA,A,3,/Operating in 3D mode with satelites:\t/; s/\$GPGSA,A,2,/Operating in 2D mode with satelites:\t/; s/\$GPGSA,A,1,/Fix not available. Satelites\t/' | cut -d',' -f 1-12
```
### 5. Show LAT LON data
```bash
sudo cat /dev/ttyACM2 | stdbuf -oL grep -a GPRMC | stdbuf -oL cut -d',' -f 4-7 | stdbuf -oL tr ',' '\t' | awk '{printf("%.8f %s -%.8f %s\n",$1/100,$2,$3/100,$4)}'
```

## License

Not coppywritten not licenced, take this for free! Use it! Sell it! Change it! do whatever you want!

## References
 1. [GPS with Ericcson device](http://www.thinkwiki.org/wiki/Ericsson_H5321_gw_Mobile_Broadband_Module#gpsd)  
 2. [Using the Ericcson device](http://www.thinkwiki.org/wiki/Ericsson_F3507g_Mobile_Broadband_Module#Using_the_card_as_a_GPS_receiver)  
 3. [NMEA codes](http://aprs.gids.nl/nmea/#gsa)  
