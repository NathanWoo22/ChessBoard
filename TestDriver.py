import serial
import time


arduino = serial.Serial(port='COM5', baudrate=9600, timeout=.1)

while True:
    num = input("Enter a number: ") # Taking input from user
    arduino.write(bytes(num, 'utf-8'))
    # arduino.write(int(num))
    time.sleep(0.05)
    data = arduino.readline().decode()
    print(data, end ="")
    # print(value) # printing the value