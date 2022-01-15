#include <LiquidCrystal.h>
LiquidCrystal lcd (7,6,5,4,3,2);

//inisialisasi pin motor
int kiriA = 11; 
int kiriB = 10;
int kananA = 13;
int kananB = 14;

//inisialisasi pin sensor ultrasonic 
int echo = A0;
int trig = A1;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (kiriA,OUTPUT);
pinMode (kiriB,OUTPUT);
pinMode (kananA,OUTPUT);
pinMode (kananB,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 long duration, inch , cm;
 pinMode(trig,OUTPUT);
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

 pinMode(echo, INPUT);
 duration = pulseIn(echo,HIGH);
 inch = microsecondsToInch(duration);
 cm = microsecondsToCm(duration);
 Serial.print(inch);
 Serial.print(" inch, ");
 Serial.print(cm);
 Serial.print(" cm, ");
 Serial.println();
 delay(100);
 if(cm<=50){
  analogWrite(kiriA,255);
  analogWrite(kiriB,0);
  analogWrite(kananA,0);
  analogWrite(kananB,255);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Ada Halangan");
  }else {
    analogWrite(kiriA,0);
  analogWrite(kiriB,255);
  analogWrite(kananA,0);
  analogWrite(kananB,255);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Aman");
    }
}

//inisialisasi konversi ke inch dan cm 
long microsecondsToInch(long microseconds){
  return microseconds/74/2;
}
long microsecondsToCm(long microseconds){
  return microseconds/29/2;
}
