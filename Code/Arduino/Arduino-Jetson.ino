  
 
// Speed control potentiometers
 
int Jets_PWM = A0;  
 
int avg_PWM;
// Motor Speed Values - Start at zero
 
int Int_PWM = 0;
 
void setup()
 
{
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  
   
}
 
void loop() {
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
  }
  else{
    Serial.println("right");
  }

  
}
