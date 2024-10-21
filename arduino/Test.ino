String serData;
int pin = 07;

void turnOn ();
void turnOff();

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  while(Serial.available() > 0) {
    char rec = Serial.read();
    serData += rec;

    if (rec == '\n'){
      Serial.print("Message recieved: ");
      Serial.println(serData);
      if (strcmp(serData.c_str(), "on\n") == 0){
        digitalWrite(pin, HIGH);
        //turnOn();
      } else if (strcmp(serData.c_str(), "off\n") == 0){
        digitalWrite(pin, LOW);  
        //turnOff();
      }
      serData = "";    
    }
  }
  delay(10);
}

void turnOn (){
  digitalWrite(pin, HIGH);
}

void turnOff() {
  digitalWrite(pin, LOW);  
}
