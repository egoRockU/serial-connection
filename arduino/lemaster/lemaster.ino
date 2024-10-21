void setup() {
  Serial.begin(9600);
  pinMode(07, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    String msg = Serial.readString();
    msg.trim();
    Serial.println(msg);
    if (msg == "on"){
      digitalWrite(07, HIGH);
    }
    else if (msg == "off"){
      digitalWrite(07, LOW);
    }
  }
}
