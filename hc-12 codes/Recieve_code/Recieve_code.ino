#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


const byte HC12RxdPin = 4;                  // Recieve Pin on HC12
const byte HC12TxdPin = 5;                  // Transmit Pin on HC12

SoftwareSerial HC12(HC12TxdPin,HC12RxdPin);
void setup() {
 Serial.begin(9600);                       
 HC12.begin(9600);  
 display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
}

void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  if(HC12.available()){
    display.println(HC12.readString());
  }
  delay(10);
}
