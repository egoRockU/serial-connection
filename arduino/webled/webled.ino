String inByt;

void setup() {
  pinMode(07, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  //
    inByt = Serial.readStringUntil('\n');
   
    if (inByt == "on") {
        digitalWrite(07, HIGH);
    } else if (inByt == "off") {
        digitalWrite(07, LOW);
    } else {
        continue;
    }
}

//void serialEvent() {
//    inByt = Serial.readStringUntil('\n');
//   
//    if (inByt == "on") {
//        digitalWrite(07, HIGH);
//    } else if (inByt == "off") {
//        digitalWrite(07, LOW);
//    } else {
//        continue;
//    }
//}
