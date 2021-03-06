#include <Servo.h>
int triggerPin = 8;
int servoPin = 2;
int echoPin = 7;
int led = 9;
int pot = A0;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 5;
int BIN2 = 6;

Servo servo;


void setup()  {
  Serial.begin(19200);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
  servo.attach(servoPin);
}

void loop() {
 int val;
 val = analogRead(pot);
 analogWrite(led, val/4);
 analogWrite(100, 128);
 analogWrite(100, 200/4);
 Serial.println("inches");
 delay(60);
 servo.write(0);
 delay(1000);
 servo.write(90);
 delay(1000);
 
 servo.write(180);
 delay(1000);
}

float ping() {
 unsigned long maxTime = 20000;
 unsigned long us;
 float inches;
 digitalWrite(triggerPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(triggerPin, LOW);
 us = pulseIn(echoPin, HIGH, maxTime);
 if (us == 0) {
 us = maxTime;
 }
 inches = us * 0.013504 / 2;
 return inches;
}
