
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
//Setting up the HC12 module for pins and start 
const byte HC12RxdPin = 12;                  // Recieve Pin on HC12
const byte HC12TxdPin = 13;                  // Transmit Pin on HC12
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port
String message, incomingmessage;

void setup() {                      
  HC12.begin(9600);  
  //String call out
  message = String("");
  incomingmessage = String("");
  // initialize with the I2C addr 0x3C (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  HC12.setTimeout(10);
}
void loop(){
  display.clearDisplay();
  incomingmessage = HC12.readString();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Message NAME: ");
  display.println(incomingmessage.substring(incomingmessage.length() - 4,incomingmessage.length()));
  display.print("Message length: ");
  display.println(incomingmessage.length());
  display.print("Message: ");
  incomingmessage.remove((incomingmessage.length() - 4), 4);
  display.println(incomingmessage);
  display.display();  
  delay(1000);
}


