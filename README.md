# Lenovo X240 WWAN

## Synopsis

Do you have a Lenovo X240? Did you buy a WWAN card for it? Want to mess around? This project is me doing that. I found out how to make the gps work.. That's kinda cool.

## Motivation

Ever since I was six years old I have always dreamed of communicating with my WWAN card over a serial connection and activating it's GPS module. Passion is a strange beast and one never knows exactly which passions will appear in which people. For me it was the Ericsson Business Mobile Networks BV WWAN card. I have fulfilled my childhood dream

## Installation and Requirements

1. Ericsson N5321 WWAN card
2. Computer that can connect to said WWAN card
3. Linux packages:
	- screen OR cu OR your favorite serial talky program
4. 

## Code

### 1. Print a bunnch of info
'''
./info.sh
'''

### 2. Configure GPS
'''
sudo screen /dev/ttyACM1
'''
Then type (all caps): AT  
You will be unable to see your inputted text but when you hit enter the device should respond: OK  


### 3. 

## License

Not coppywritten not licenced, take this for free! Use it! Sell it! Change it! do whatever you want!
