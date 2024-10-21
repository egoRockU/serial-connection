import serial

with serial.Serial('COM4', 9600) as ser:
    x = ser.readline()
    print(x)

    msg = "Test\n"
    ser.write(msg.encode())
    y = ser.readline()
    print(y)

    ser.close()