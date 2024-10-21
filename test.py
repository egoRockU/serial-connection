import serial

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM4'
ser.open()

msg = 'on\n'
ser.write(msg.encode('utf-8'))
ser.close()
