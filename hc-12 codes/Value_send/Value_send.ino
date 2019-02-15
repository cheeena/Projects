//HC-12 AT Commander
//Autor Tom Heylen tomtomheylen.com
//The HC-12 commander mode runs at baud rate 9600

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(1200);
  Serial.println("Enter AT commands:");
  mySerial.begin(1200);
}

void loop(){
  if (mySerial.available()){
    Serial.write(mySerial.read());
  }
  if (Serial.available()){
    mySerial.write(Serial.read());
  }
}

