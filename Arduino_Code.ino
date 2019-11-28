#include <LiquidCrystal.h> 
#include <SoftwareSerial.h>
#define mot1 6
#define mot2 7
#define mot3 8
#define mot4 9
unsigned char data;
void forward();
void reverse();
void left();
void right();
void stop1();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  digitalWrite(mot1, LOW);
  digitalWrite(mot4, LOW);
  digitalWrite(mot2, LOW);
  digitalWrite(mot3, LOW);
 lcd.print(" WI-FI ROBO-CAR ");
   delay(6000);
  Serial.begin(9600);
  Serial.read();
  lcd.autoscroll();
  lcd.print("   MONITORING...   ");
  Serial.read();
}
  void loop()
  {  while(!Serial.available())
 {
} 
    if(Serial.available())
    { 
      lcd.clear();
      data=Serial.read();
      if(data=='F'||data=='f' ){forward();}   
      else if(data=='B'||data=='b'){reverse();}
      else if(data=='L' ||data=='l'){left();}      
      else if(data=='R'||data=='r'){right();}   
      else if(data=='S'||data=='s'){stop1();}
      Serial.read();
    }  }   
void forward()
{  digitalWrite(mot1, HIGH);
  digitalWrite(mot4, HIGH);
  digitalWrite(mot2, LOW);
  digitalWrite(mot3, LOW); }
void reverse()
{  digitalWrite(mot2, HIGH);
  digitalWrite(mot3, HIGH);
  digitalWrite(mot1, LOW);
  digitalWrite(mot4, LOW); }
void right()
{  digitalWrite(mot2, HIGH);
  digitalWrite(mot4, HIGH);
  digitalWrite(mot1, LOW);
  digitalWrite(mot3, LOW); }
void left()
{ digitalWrite(mot1, HIGH);
  digitalWrite(mot3, HIGH);
  digitalWrite(mot2, LOW);
  digitalWrite(mot4, LOW); }
void stop1()
{   digitalWrite(mot1, LOW);
  digitalWrite(mot4, LOW);
  digitalWrite(mot2, LOW);
  digitalWrite(mot3, LOW);  }
