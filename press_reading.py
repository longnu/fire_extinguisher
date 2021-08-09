import serial
import time

port = '/dev/ttyACM0'
serialFromArduino = serial.Serial(port, 9600)
serialFromArduino.flushInput()

while True :
    input_s = serialFromArduino.readline()
    result_str = str(input_s, 'utf-8')
    result_int = int(result)
    time.sleep(5)
    
    
