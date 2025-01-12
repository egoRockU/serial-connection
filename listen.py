from flask import Flask, render_template, request
from serial import Serial
import time
import threading

SERIAL = "COM13"
app = Flask(__name__)
ser = Serial()
ser.baudrate = 115200
ser.port = SERIAL
ser.timeout = 1

data_buffer = []

@app.route('/')
def hello_world():
   return data_buffer


def serial_listen():
   time.sleep(5)
   ser.open()
   while True:
      if ser.in_waiting:
         data = ser.readline().decode('utf8').strip()
         if 'OBJECT DETECTED!' in data:
            data_buffer.append(data.split(" ")[2])

if __name__ == '__main__':
    # Start the serial listener thread
    listener_thread = threading.Thread(target=serial_listen, daemon=True)
    listener_thread.start()

    # Run the Flask app
    app.run(debug=True)
