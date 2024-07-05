# 12.	Using putty make a remote connection to raspberry pi and write a python program to blink a LED

# Refer the Raspberry_pi_instructions.pdf document for procedure inside MC-IOT folder itself.

# only pytohn file

import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
while(1):
	GPIO.output(18, GPIO.HIGH)
	time.sleep(3)
	GPIO.output(18, GPIO.LOW) 
	time.sleep(3)
GPIO.cleanup()
