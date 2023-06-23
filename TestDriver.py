import serial
import time


arduino = serial.Serial(port='COM5', baudrate=115200, timeout=.1)
def write_read(x):
    
    time.sleep(0.05)
    data = arduino.readline()
    return data
while True:
    num = input("Enter a number: ") # Taking input from user
    arduino.write(bytes(num, 'utf-8'))
    # print(value) # printing the value