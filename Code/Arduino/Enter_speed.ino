const int IN1=8;
const int IN2=7;
const int ENA=9;
const int IN3=5;
const int IN4=4;
const int ENB=6;

void setup() {
 Serial.begin(9600);
 Serial.setTimeout(1000000);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(ENA, OUTPUT);

 pinMode(IN4, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(ENB, OUTPUT);
}

void loop() {
  int speed;
  Serial.println("Enter Angle 1 (-180 to 180):");
  while(!Serial.available())
  {}
  speed = Serial.parseInt();
  Motor1_Backward(speed);
  delay(1000);
}

void Motor1_Forward(int Speed)
{
 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 analogWrite(ENA,Speed);
}

void Motor1_Backward(int Speed)
{
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 analogWrite(ENA,Speed);
}
void Motor1_Brake()
{
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,LOW);
}
void Motor2_Forward(int Speed)
{
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 analogWrite(ENB,Speed);
}

void Motor2_Backward(int Speed)
{
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 analogWrite(ENB,Speed);
}
void Motor2_Brake()
{
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,LOW);
}
