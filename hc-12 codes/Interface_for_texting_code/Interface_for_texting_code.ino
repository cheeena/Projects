/*
  Appending to Strings using the += operator and concat()

  Examples of how to append different data types to Strings

  created 27 Jul 2010
  modified 2 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/StringAppendOperator
*/
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

const byte HC12RxdPin = 12;                  // Recieve Pin on HC12
const byte HC12TxdPin = 13;                  // Transmit Pin on HC12
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port

//chars for use
char chars[58] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.?!";
// Pins for use and thier use
int pinup = 2;
int pindown = 3;
int pinleft = 4;
int pinright = 5;
int pinselect = 6;
int pinsend = 7;
int pincap = 8;
int pinspace = 9;
int pinswitch = 10;
//the X Y Axies
int x = 0;
int y = 0;
//calling out message as a string
String message;
//ints to make the letters stand out
int a,b,c,d,e,f,g,h,I,j,k,l,m,n,o,p,q,r,s,t,u,v,w,X,Y,z,comma,period,question,exc,space,cap,snd;
//int for the switch button
int i;

String stringOne, stringTwo;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  stringOne = String("Sensor ");
  stringTwo = String("value");
  message = String("hello");
  // send an intro:
  Serial.println("\n\nAppending to a String:");
  Serial.println();
}

void loop() {
  for(i = 0; i <20; i++){
  message += chars[i];
  Serial.println(message);  // prints "Sensor value"
  }
  display.setTextSize(1);
  display.setTextColor(space,WHITE);
  display.setCursor(96,17);
  display.println("SPACE");
  display.setTextSize(1);
  display.setTextColor(cap,WHITE);
  display.setCursor(96,35);
  display.println("CAP");
  display.setTextSize(1);
  display.setTextColor(snd,WHITE);
  display.setCursor(96,53);
  display.println("SEND");
  display.setTextColor(a,WHITE);
  display.setCursor(0,17);
  display.println("a");
  display.setTextColor(b,WHITE);
  display.setCursor(16,17);
  display.println("b");
  display.setTextColor(c,WHITE);
  display.setCursor(32,17);
  display.println("c");
  display.setTextColor(d,WHITE);
  display.setCursor(48,17);
  display.println("d");
  display.setTextColor(e,WHITE);
  display.setCursor(64,17);
  display.println("e");
  display.setTextColor(f,WHITE);
  display.setCursor(80,17);
  display.println("f");
  display.setTextColor(g,WHITE);
  display.setCursor(0,26);
  display.println("g");
  display.setTextColor(h,WHITE);
  display.setCursor(16,26);
  display.println("h");
  display.setTextColor(I,WHITE);
  display.setCursor(32,26);
  display.println("i");
  display.setTextColor(j,WHITE);
  display.setCursor(48,26);
  display.println("j");
  display.setTextColor(k,WHITE);
  display.setCursor(64,26);
  display.println("k");
  display.setTextColor(l,WHITE);
  display.setCursor(80,26);
  display.println("l");
  display.setTextColor(m,WHITE);
  display.setCursor(0,35);
  display.println("m");
  display.setTextColor(n,WHITE);
  display.setCursor(16,35);
  display.println("n");
  display.setTextColor(o,WHITE);
  display.setCursor(32,35);
  display.println("o");
  display.setTextColor(p,WHITE);
  display.setCursor(48,35);
  display.println("p");
  display.setTextColor(q,WHITE);
  display.setCursor(64,35);
  display.println("q");
  display.setTextColor(r,WHITE);
  display.setCursor(80,35);
  display.println("r");
  display.setTextColor(s,WHITE);
  display.setCursor(0,44);
  display.println("s");
  display.setTextColor(t,WHITE);
  display.setCursor(16,44);
  display.println("t");
  display.setTextColor(u,WHITE);
  display.setCursor(32,44);
  display.println("u");
  display.setTextColor(v,WHITE);
  display.setCursor(48,44);
  display.println("v");
  display.setTextColor(w,WHITE);
  display.setCursor(64,44);
  display.println("w");
  display.setTextColor(X,WHITE);
  display.setCursor(80,44);
  display.println("x");
  display.setTextColor(Y,WHITE);
  display.setCursor(0,53);
  display.println("y");
  display.setTextColor(z,WHITE);
  display.setCursor(16,53);
  display.println("z");
  display.setTextColor(comma,WHITE);
  display.setCursor(32,53);
  display.println(",");
  display.setTextColor(period,WHITE);
  display.setCursor(48,53);
  display.println(".");
  display.setTextColor(question,WHITE);
  display.setCursor(64,53);
  display.println("?");
  display.setTextColor(exc,WHITE);
  display.setCursor(80,53);
  display.println("!");
  display.setCursor(0,0);
  display.println(message);
  display.display();
  display.clearDisplay();
delay(300);
}
