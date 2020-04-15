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
We will be connecting to the **N5321 gw Mobile Broadband Data Modem** to configre the device and **N5321 gw Mobile Broadband Modem** to activate the GPS. The GPS data will be outputed on **N5321 gw Mobile Broadband GPS Port**. Given my output that means I will first connect to ```/dev/ttyACM1```, then ```/dev/ttyACM0```, and then ```/dev/ttyACM2```.

### 2. Configure GPS
```
sudo screen /dev/ttyACM1
```
Then type (all caps):
```
AT
```
You may be unable to see your inputted text but when you hit enter the device should respond: OK  
Then type (all caps):
```
AT*E2GPSCTL=1,5,1
```
Slam enter, then exit the serial connection .  

### 3. Activate GPS
```
sudo screen /dev/ttyACM2
AT*E2GPSNPD
```
Hit enter and bam, boom. You got GPS data

### 4. Wait for satelites
May work best outdoors
```
sudo cat /dev/ttyACM2 | grep -a GPGSA
```

### 5. Show LAT LON data
```
sudo cat /dev/ttyACM2 | grep -a GPRMC
```

## License

Not coppywritten not licenced, take this for free! Use it! Sell it! Change it! do whatever you want!
