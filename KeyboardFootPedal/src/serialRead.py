import serial.tools.list_ports
import sys
from pynput.keyboard import Key, Controller

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portList = []

for onePort in ports:
    portList.append(str(onePort))
    print(str(onePort)) # list all COM inputs

val = input("Select Port: COM") # val = what you type in

for x in range(0,len(portList)):
    if portList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portList[x])
        break
    elif x == len(portList)-1:
        sys.exit("No port with that value")

serialInst.baudrate = 9600
serialInst.port = portVar
serialInst.open()

keyboard = Controller()

while True:
    if serialInst.in_waiting:
        arduinoData = serialInst.readline().decode('utf') # read as unicode
        print(arduinoData[0]) # Print only first character

        if arduinoData[0] == "f":
            keyboard.press(Key.enter)
            keyboard.release(Key.enter)
        else:
            keyboard.press(arduinoData[0])
            keyboard.release(arduinoData[0])

