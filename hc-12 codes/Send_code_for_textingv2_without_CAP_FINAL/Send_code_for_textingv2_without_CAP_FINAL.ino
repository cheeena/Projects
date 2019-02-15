/*
 * BUTTON PINS:
 * D2 = UP 
 * D3 = DOWN
 * D4 = LEFT
 * D5 = RIGHT
 * D6 = SELECT
 * D7 = SEND
 * D8 = SPACE
 * D9 = SWITCH MODE
 * 
 * HC12 PINS:
 * D12 = RX
 * D13 = TX
 * 
 * OLED SCREEN PINS;
 * A4 = SDA
 * A5 = SCL
 * 
 * NOTES:
 * If you use the default options on the HC.12 code than the full range is not
 * utilized. See HC.12 AT commands for more information 
 * 
 * This code is very versatile and can be used for other RF hardware such as 
 * rf22, rf24, LoRa modules with small changes to only send and recieve commands
 * 
 * Make sure that there is 25uf CAP on the VCC and GND just in case large data 
 * sends with small batteries. The module is also supposed to be powered by an 
 * external power supply (not an arduino)
 * 
 * Final and most imprtant is that the code is a bit too long and takes up a lot
 * of the SRAM which means if it recieves a large string it will freeze and the 
 * switch button must be called to set the recieve string back to ""
 * 
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
//Setting up the HC12 module for pins and start 
const byte HC12RxdPin = 12;                  // Recieve Pin on HC12
const byte HC12TxdPin = 13;                  // Transmit Pin on HC12
SoftwareSerial HC12(HC12TxdPin,HC12RxdPin); // Create Software Serial Port
//chars for use
char chars[31] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.?!";
// Pins for use and thier use
int pinup = 2;
int pindown = 3;
int pinleft = 4;
int pinright = 5;
int pinselect = 6;
int pinsend = 10;
int pinspace = 8;
int pinswitch = 9;
int pinbackspace = 7;
//the X Y Axies
int x = 0;
int y = 0;
//calling out message as a string
String message, incomingmessage;
//ints to make the letters stand out
int a,b,c,d,e,f,g,h,I,j,k,l,m,n,o,p,q,r,s,t,u,v,w,X,Y,z,comma,period,question,exc,space,cap,snd,backspace;
//int for the switch button
int i = 1;
/////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {                      
  HC12.begin(9600);  
  //Pull-up all the pins for stable press
  digitalWrite(pinup, HIGH);
  digitalWrite(pindown, HIGH);
  digitalWrite(pinleft, HIGH);
  digitalWrite(pinright, HIGH);
  digitalWrite(pinselect, HIGH);
  digitalWrite(pinsend, HIGH);
  digitalWrite(pinspace,HIGH);
  digitalWrite(pinswitch,HIGH);
  digitalWrite(pinbackspace,HIGH);
  //String call out
  message = String("");
  incomingmessage = String("");
  // initialize with the I2C addr 0x3C (for the 128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.display();
  display.clearDisplay(); 
  //Setting the time needed to read the serial port(30 mili is limited to 42 chars at a time
  //but can be increased for larger transmissions
  HC12.setTimeout(30);
}
void loop(){
  int buttonswitch = digitalRead(pinswitch);
  
    if(buttonswitch == LOW){     
      i++;   
      incomingmessage = String("");
      delay(300);             
    }

    if((i % 2) == 0){
      sendcode();        
    }
    else{
      recievecode();
    }
    
}
void recievecode(){
  display.clearDisplay();
  incomingmessage += HC12.readString();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(12,0);
  display.print("INCOMING MESSAGE");
  display.setCursor(0,8);
  display.println(incomingmessage);
  display.display();
}
////////////////////////////////////////////////////////////////////////////////////////////////
void sendcode(){
//Button callout
 int buttonup = digitalRead(pinup);
 int buttondown = digitalRead(pindown);
 int buttonleft = digitalRead(pinleft);
 int buttonright = digitalRead(pinright);
 int buttonselect = digitalRead(pinselect);
 int buttonsend = digitalRead(pinsend);
 int buttonspace = digitalRead(pinspace);
 int buttonbackspace = digitalRead(pinbackspace);
///////////////////////////////////////////
//Char variables
 int charnum;
 int capchar = 0;
///////////////////////////////////////////
//The XY button controllers
 if(buttonup == LOW){
  y--;
   if(y < 0){
     y++;
    }
  delay(200);
 }
  if(buttondown == LOW){
  y++;
  if(y > 4){
    y--;
  }
  delay(200);
 }
  if(buttonright == LOW){
  x++;
  if(x > 5){
    x--;
  }
  delay(200);
 }
  if(buttonleft == LOW){
  x--;
  if(x < 0){
    x++;
  }
  delay(200);
 } 
///////////////////////////////////////////
//All the configs for each char
 if((y == 0) && (x == 0)){
  charnum = 0;
  a = BLACK;
 }
 else{
  a = WHITE;
 }
  if((y == 0) && (x == 1)){
  charnum = 1;
  b = BLACK;
 }
 else{
  b = WHITE;
 }
  if((y == 0) && (x == 2)){
  charnum = 2;
  c = BLACK;
 }
 else{
  c = WHITE;
 }
  if((y == 0) && (x == 3)){
  charnum = 3;
  d = BLACK;
 }
 else{
  d = WHITE;
 }
  if((y == 0) && (x == 4)){
  charnum = 4;
  e = BLACK;
 }
 else{
  e = WHITE;
 }
  if((y == 0) && (x == 5)){
  charnum = 5;
  f = BLACK;
 }
 else{
  f = WHITE;
 }
  if((x == 0) && (y == 1)){
  charnum = 6;
  g = BLACK;
 }
 else{
  g = WHITE;
 }
  if((x == 1) && (y == 1)){
  charnum = 7;
  h = BLACK;
 }
 else{
  h = WHITE;
 }
  if((x == 2) && (y == 1)){
  charnum = 8;
  I = BLACK;
 }
 else{
  I = WHITE;
 }
  if((x == 3) && (y == 1)){
  charnum = 9;
  j = BLACK;
 }
 else{
  j = WHITE;
 }
  if((x == 4) && (y == 1)){
  charnum = 10;
  k = BLACK;
 }
 else{
  k = WHITE;
 }
  if((x == 5) && (y == 1)){
  charnum = 11;
  l = BLACK;
 }
 else{
  l = WHITE;
 }
  if((x == 0) && (y == 2)){
  charnum = 12;
  m = BLACK;
 }
 else{
  m = WHITE;
 }
  if((x == 1) && (y == 2)){
  charnum = 13;
  n = BLACK;
 }
 else{
  n = WHITE;
 }
  if((x == 2) && (y == 2)){
  charnum = 14;
  o = BLACK;
 }
 else{
  o = WHITE;
 }
  if((x == 3) && (y == 2)){
  charnum = 15;
  p = BLACK;
 }
 else{
  p = WHITE;
 }

  if((x == 4) && (y == 2)){
  charnum = 16;
  q = BLACK;
 }
 else{
  q = WHITE;
 }

  if((x == 5) && (y == 2)){
  charnum = 17;
  r = BLACK;
 }
 else{
  r = WHITE;
 }

  if((x == 0) && (y == 3)){
  charnum = 18;
  s = BLACK;
 }
 else{
  s = WHITE;
 }

  if((x == 1) && (y == 3)){
  charnum = 19;
  t = BLACK;
 }
 else{
  t = WHITE;
 }

  if((x == 2) && (y == 3)){
  charnum = 20;
  u = BLACK;
 }
 else{
  u = WHITE;
 }

  if((x == 3) && (y == 3)){
  charnum = 21;
  v = BLACK;
 }
 else{
  v = WHITE;
 }

  if((x == 4) && (y == 3)){
  charnum = 22;
  w = BLACK;
 }
 else{
  w = WHITE;
 }

  if((x == 5) && (y == 3)){
  charnum = 23;
  X = BLACK;
 }
 else{
  X = WHITE;
 }

  if((x == 0) && (y == 4)){
  charnum = 24;
  Y = BLACK;
 }
 else{
  Y = WHITE;
 }
  if((x == 1) && (y == 4)){
  charnum = 25;
  z = BLACK;
 }
 else{
  z = WHITE;
 }

  if((x == 2) && (y == 4)){
  charnum = 26;
  comma = BLACK;
 }
 else{
  comma = WHITE;
 }

  if((x == 3) && (y == 4)){
  charnum = 27;
  period = BLACK;
 }
 else{
  period = WHITE;
 }
 if((x == 4) && (y == 4)){
  charnum = 28;
  question = BLACK;
 }
 else{
  question = WHITE;
 }
 if((x == 5) && (y == 4)){
  charnum = 29;
  exc = BLACK;
 }
 else{
  exc = WHITE;
 }
///////////////////////////////////////////
//SPACE button callout
 if(buttonspace == LOW){
  message += ' ';
  space = BLACK;
  delay(200);
 }
 else{
  space = WHITE;
 }
///////////////////////////////////////////
//Adding all the chars together to make a message
if(buttonselect == LOW){
    message += chars[charnum];
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(message);
    delay(200);
  }
///////////////////////////////////////////
//Backspace funcntion
if(buttonbackspace == LOW){
  message.remove(message.length() - 1);
  backspace = BLACK;
  delay(200);
}
else{
  backspace = WHITE;
}
///////////////////////////////////////////
//MAX char limit. can be set to somthing higher if your screen bigger.
//For I2C oled its the first two lines  
if(message.length() > 42){
  message.remove(message.length() - 1);
}
///////////////////////////////////////////
//Final step in sending the message and reseting the message back to nothing(space)
  if(buttonsend == LOW){
    snd = BLACK;
    HC12.print(message);
    message = String("");
    delay(200);
  }
  else{
    snd = WHITE;
  }
///////////////////////////////////////////
//Display print out and locations of each character 
  display.setTextSize(1);
  display.drawLine(1, 16, 1, 61, WHITE);
  display.drawLine(11, 16, 11, 61, WHITE);//Vertical Lines
  display.drawLine(21, 16, 21, 61, WHITE);
  display.drawLine(31, 16, 31, 61, WHITE);
  display.drawLine(41, 16, 41, 61, WHITE);
  display.drawLine(51, 16, 51, 61, WHITE);
  display.drawLine(61, 16, 61, 61, WHITE);
  display.drawLine(1, 16, 60, 16, WHITE);//Horizontal Lines
  display.drawLine(1, 25, 60, 25, WHITE);
  display.drawLine(1, 34, 60, 34, WHITE);
  display.drawLine(1, 43, 60, 43, WHITE);
  display.drawLine(1, 52, 60, 52, WHITE);
  display.drawLine(1, 61, 60, 61, WHITE);
  display.setTextColor(space,WHITE);
  display.setCursor(83,17);
  display.println("SPACE");
  display.setTextColor(backspace,WHITE);
  display.setCursor(85,35);
  display.println("BACK");
  display.setTextColor(snd,WHITE);
  display.setCursor(85,53);
  display.println("SEND");
  display.setTextColor(a,WHITE);
  display.setCursor(4,17);
  display.println('A');
  display.setTextColor(b,WHITE);
  display.setCursor(14,17);
  display.println('B');
  display.setTextColor(c,WHITE);
  display.setCursor(24,17);
  display.println('C');
  display.setTextColor(d,WHITE);
  display.setCursor(34,17);
  display.println('D');
  display.setTextColor(e,WHITE);
  display.setCursor(44,17);
  display.println('E');
  display.setTextColor(f,WHITE);
  display.setCursor(54,17);
  display.println('F');
  display.setTextColor(g,WHITE);
  display.setCursor(4,26);
  display.println('G');
  display.setTextColor(h,WHITE);
  display.setCursor(14,26);
  display.println('H');
  display.setTextColor(I,WHITE);
  display.setCursor(24,26);
  display.println('I');
  display.setTextColor(j,WHITE);
  display.setCursor(34,26);
  display.println('J');
  display.setTextColor(k,WHITE);
  display.setCursor(44,26);
  display.println('K');
  display.setTextColor(l,WHITE);
  display.setCursor(54,26);
  display.println('L');
  display.setTextColor(m,WHITE);
  display.setCursor(4,35);
  display.println('M');
  display.setTextColor(n,WHITE);
  display.setCursor(14,35);
  display.println('N');
  display.setTextColor(o,WHITE);
  display.setCursor(25,35);
  display.println('O');
  display.setTextColor(p,WHITE);
  display.setCursor(34,35);
  display.println('P');
  display.setTextColor(q,WHITE);
  display.setCursor(44,35);
  display.println('Q');
  display.setTextColor(r,WHITE);
  display.setCursor(54,35);
  display.println('R');
  display.setTextColor(s,WHITE);
  display.setCursor(4,44);
  display.println('S');
  display.setTextColor(t,WHITE);
  display.setCursor(14,44);
  display.println('T');
  display.setTextColor(u,WHITE);
  display.setCursor(24,44);
  display.println('U');
  display.setTextColor(v,WHITE);
  display.setCursor(34,44);
  display.println('V');
  display.setTextColor(w,WHITE);
  display.setCursor(44,44);
  display.println('W');
  display.setTextColor(X,WHITE);
  display.setCursor(54,44);
  display.println('X');
  display.setTextColor(Y,WHITE);
  display.setCursor(4,53);
  display.println('Y');
  display.setTextColor(z,WHITE);
  display.setCursor(14,53);
  display.println('Z');
  display.setTextColor(comma,WHITE);
  display.setCursor(24,53);
  display.println(',');
  display.setTextColor(period,WHITE);
  display.setCursor(34,53);
  display.println('.');
  display.setTextColor(question,WHITE);
  display.setCursor(44,53);
  display.println('?');
  display.setTextColor(exc,WHITE);
  display.setCursor(54,53);
  display.println('!');
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(message);
  display.display();
  display.clearDisplay();
  ///////////////////////////////////////////
  //Small delay just in case
  delay(10);
 
}
 




