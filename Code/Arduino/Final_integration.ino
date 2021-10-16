#include "VarSpeedServo.h"
// PWM Initialising
int Jets_PWM = A0;  
int avg_PWM;
int Int_PWM = 0;
// MOTOR Initialising
const int IN1=8;
const int IN2=7;
const int ENA=9;
const int IN3=5;
const int IN4=6;
const int ENB=4;
// SERVO Initialising
VarSpeedServo horizontal_servo, vertical_servo, pusher_servo;

//Setup
void setup()
{
  Serial.begin(9600);
  pinMode(Jets_PWM, INPUT); // get rid if this changes jetson-arduino communication
  // MOTOR pins to outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENB, OUTPUT);
  // SERVO Pins
  horizontal_servo.attach(10);
  vertical_servo.attach(2);
  pusher_servo.attach(3);
   
}

// Main Loop
void loop() 
{
  int direction = Player_Direction();
  // Decide Motors speeds, and horizontal_servo and vertical_servo angles
  // Call Motor_Control Func
  // Call Directional_Control Func
  // Call Pusher Func  
  Pusher(2);
  Directional_Control(120, 20);

}

// PWM jetson DIRECTION FUNCTION
int Player_Direction() 
{
  int count = 0;
  for (int i = 0; i< 200; i ++) {
    // Read the values from the Jetson Nano
    Int_PWM = analogRead(Jets_PWM);
  
    // Convert to range of 0-255
    Int_PWM = map(Int_PWM, 0, 1023, 0, 255);
    // Add to average count
    count = count + Int_PWM;
  }
  avg_PWM = count/200;
  if (avg_PWM>0){
    return 0; // left
  }
  else{
    return 1; //right
  }  
}

// MOTOR CONTROL FUNCTION
void Motor_Control(int Speed1, int Speed2)
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA,Speed1);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,Speed2);
}
// DIRECTIONAL CONTROL FUNCTION
void Directional_Control(int theta1, int theta2)
{
  if (theta1>=60 && theta1<=120){
    horizontal_servo.write(theta1);
  }
  delay(100); // 50ms
  if (theta2>=20 && theta2<=70){
    vertical_servo.write(theta2);
  }
}

// PUSHER FUNCTION
void Pusher(int freq)
{
  pusher_servo.write(90,30); 
  delay(1000*freq); // 50ms // Make dependent on freq__
  pusher_servo.write(140,30); 
  delay(1000);
}
