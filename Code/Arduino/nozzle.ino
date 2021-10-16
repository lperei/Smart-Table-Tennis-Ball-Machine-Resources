#include "VarSpeedServo.h"

VarSpeedServo servo1, servo2, servo3, servo4;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int theta1, theta2, theta3, theta4;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000000);
//  servo1.attach(7);
//  servo2.attach(8);
//  servo3.attach(4);
  servo4.attach(6);// attaches the servo on pin 9 to the servo object
}

void loop() {
  // Asking Players to Enter numbers
//  Serial.println("Enter Angle 1:");
//  while(!Serial.available())
//  {}
//  theta1 = Serial.parseInt();
//  Serial.println(theta1);
//  servo1.write(theta1);
//  Serial.println("Enter Angle 2:");
//  while(!Serial.available())
//  {}
//  theta2 = Serial.parseInt();
//  servo4.write(theta2);
//  Serial.println(theta2);
//  Serial.println("Enter Angle 3:");
//  while(!Serial.available())
//  {}
//  theta3 = Serial.parseInt();
//  Serial.println(theta3);
//  servo3.write(theta3);
//  Serial.println("Enter Angle 4:");
//  while(!Serial.available())
//  {}
//  theta4 = Serial.parseInt();
//  Serial.println(theta4);
//  servo4.write(theta4);
    servo4.write(10,30);
    delay(1000);
    servo4.write(60,30);
    delay(1000);
  
  
  
  // tell servo to go to position in variable 'pos'
//  delay(15);                       // waits 15ms for the servo to reach the position

}
