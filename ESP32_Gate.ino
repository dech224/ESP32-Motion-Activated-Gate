#include <ESP32Servo.h>


Servo myServo;

const int trig_Pin = 4;
const int echo_Pin = 18;
const int LED_Green = 2;
const int LED_Red = 5;
const int servo_Pin = 14;



void setup() {

  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Red, OUTPUT);

  Serial.begin(115200);

  //Set up for Servo
  myServo.setPeriodHertz(50);
  myServo.attach(servo_Pin);
  myServo.write(0); 
  delay(1000);

 
}

void loop() {

  //Set up for Sensor
  digitalWrite(trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_Pin, LOW);

  
  long duration = pulseIn(echo_Pin, HIGH);

  //Distance fron sensor 
  float dist = duration * 0.034 / 2;
 

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist < 15) {
    digitalWrite(LED_Green, HIGH);
    digitalWrite(LED_Red, LOW);
    myServo.write(0); 
    
  } else {
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_Red, HIGH);
    myServo.write(90); 
    
  }
  delay(100);

  }

  
