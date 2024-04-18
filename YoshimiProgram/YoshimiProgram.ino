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
int servoSpinPin = 4;
int sAngle = 170;
int startAngle = 0;

// kicker
Servo kicker;
int servoKickPin = 5;

// vitamins
int const pressPin = A1;
int pressVal = 1000;
int init_press; // the FSR (and certainly our setup for it) isn't reliable enough 
                // that we can specify values, so we're taking proportions of the initial pressure

void setup() {
  spinAround.attach(servoSpinPin); 
  spinAround.write(startAngle);
  delay(5000); // in case we need to fiddle 
  init_press = analogRead(pressPin);
  
  // debug - luckily, the user doesn't see this, so we can have it running during the demo
  Serial.begin(9600);
  Serial.println("Hello world");
  Serial.print("init_press: ");
  Serial.println(init_press);
}

void loop() {
  // there's some fluctuation in the readings even if we don't touch it, since
  // the FSR is just a resistor whose strength is affected by pressure 
  while (pressVal > 0.9 * init_press){
   pressVal = analogRead(pressPin);
   Serial.println(pressVal); // debug

   // this isn't actionable, we'll only be in this loop during idle states,
   // and we assume the user will need a second to proceed, so let's not do rapid-fire readings
  delay(5000);
  }
 
 // while the vitamins are lifted
  while (pressVal < .85 * init_press){
   pressVal = analogRead(pressPin);
   Serial.println(pressVal);
   delay(2000);
  }
 
 spinAround.write(sAngle);
 delay(1000);
 kicker.attach(servoKickPin, 360, 0);
 kicker.writeMicroseconds(2000);
 delay(1400);
 kicker.detach(); // we have a continuous servo, so we have to shut it off
 
 Serial.println(pressVal);

while (true){ // we'll hit the reset button on the board when we're ready again - 
              // in the meantime, we want to make sure the FSR is still good
  pressVal = analogRead(pressPin);
  Serial.println(pressVal);
  delay(1000);
}

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