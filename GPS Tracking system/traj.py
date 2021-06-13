import serial

from serial import Serial

from time import localtime, strftime

ser = serial.Serial()

ser.port = 'COM3'

ser.baudrate = 19600

 #ser.open()
temp_file = open('temp_traj.txt', 'a', encoding = 'utf-8')
 #temp_file = open('temp_humid.txt', 'a', encoding = 'utf-8')

while(True):
    line = ser.readline()
    print(line)
    temp_file.write(line.decode())





 #temp_file.write(strftime("%d %b %Y %H%M%S ", localtime()))

 #temp_file.write(line.decode())