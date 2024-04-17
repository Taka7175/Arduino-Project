/*
  This code is adapted from starter kit Project 5,
  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit
*/

// include the Servo library
#include <Servo.h>
// spinner
Servo spinAround;
int servoSpinPin = 5;
int sAngle = 180;

// kicker
Servo kicker;
int servoKickPin = 0;
int kAngle = 160;

// kickee
int const pressPin = A0;
int pressVal = 1000;
int pressThresh = 400;

void setup() {
  spinAround.attach(servoSpinPin); 
  kicker.attach(servoKickPin);
  
  // debug
  // Serial.begin(9600);
  // Serial.println("Hello world");
}

void loop() {
  while (pressVal > pressThresh){
    pressVal = analogRead(pressPin);
  }
  /* debug
  Serial.print("pressVal: ");
  Serial.println(pressVal);
  delay(200);*/
 
 spinAround.write(sAngle);
 delay(1000);
 kicker.write(kAngle);
 
 while (pressVal < pressThresh){
  pressVal = analogRead(pressPin);
 }

 kicker.write(kAngle);
 delay(1000);
 spinAround.write(sAngle);

 delay(10000);

 /* debug
 int loops = 0;
   // set the servo position
   while(loops <= 5)
   {
     spinAround.write(angle);
     delay(3000);
     spinAround.write(0);
     delay(3000);
     loops++;
   }
  //spinAround.write(0); 
  */
}