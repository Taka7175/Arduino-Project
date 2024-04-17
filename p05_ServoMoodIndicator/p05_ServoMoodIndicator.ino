/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors

  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

// include the Servo library
#include <Servo.h>

Servo myServo;  // create a servo object

int const potPin = A0;  // analog pin used to connect the potentiometer
int potVal;             // variable to read the value from the analog pin
int angle; 
int fsrAnalogPin = A1; // FSR is connected to analog 0
//int LEDpin = 9;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
//int LEDbrightness;             // variable to hold the angle for the servo motor

void setup() {
  myServo.attach(6); 
  //Serial.begin(9600);
    // attaches the servo on pin 9 to the servo object
  //Serial.begin(9600);  // open a serial connection to your computer
}

void loop() {
  potVal = analogRead(potPin); 
   // read the value of the potentiometer
  // print out the value to the Serial Monitor
  //Serial.print("potVal: ");
  //Serial.print(potVal);

  // scale the numbers from the pot
  //angle = map(potVal, 0, 1023, 0, 179);
  angle = 100;

  fsrReading = analogRead(fsrAnalogPin);
  myServo.write(angle);
  //Serial.println(fsrReading);
  printf(fsrReading);
  delay(1000);
  

  // print out the angle for the servo motor
  //Serial.print(", angle: ");
  //Serial.println(angle);
// int loops = 0;
//   // set the servo position
//   while(loops <= 5)
//   {
//     myServo.write(angle);
//     delay(1000);
//     myServo.write(0);
//     delay(1000);
//     loops++;
//   }
  //myServo.write(0);

// wait for the servo to get there
exit(0);  

}