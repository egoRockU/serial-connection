from flask import Flask, render_template, request
from serial import Serial
import time

SERIAL = "COM4"
app = Flask(__name__)
ser = Serial()
ser.baudrate = 9600
ser.port = SERIAL
ser.timeout = 1

@app.route('/')
def hello_world():
   time.sleep(5)
   ser.open()
   return render_template('index.html')

@app.route('/send', methods=['POST'])
def send_serial():
    value = request.form.get('value')
    print(value)

    if value == 'on':
        turnOn()
    elif value == 'off':
        turnOff()
    return render_template('index.html')

def turnOn():
   ser.write(str('on\n').encode())

def turnOff():
   ser.write(str('off\n').encode())

if __name__ == '__main__':
   app.run(debug=True)