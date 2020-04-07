from Adafruit_IO import Client
import serial
import time
import re

#No, I'm not giving you my credentials...
aio = Client('','')

arduino = serial.Serial("/dev/ttyACM0")
arduino.baudrate = 9600
data = arduino.readline()
time.sleep(0.5)
data = arduino.readline()
pieces = data.split("\t")
tempout = pieces[0]
humidout = pieces[1]

#isolate values from text
tempout = re.findall(r'\d+\.\d+', tempout)
humidout = re.findall(r'\d+\.\d+', humidout)

#send to Adafruit and remove quotes
aio.send('outsidetemp', float(tempout[0]))
aio.send('outsidehumidity', float(humidout[0]))
