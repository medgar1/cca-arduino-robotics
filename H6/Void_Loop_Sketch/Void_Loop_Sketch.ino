#include <Servo.h>
int triggerPin = 8;
int servoPin = 2;
int echoPin = 7;
int led = 9;
int pot = A0;

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
int i;
 for (i = 0; i < 180; i++) {
 Serial.println(i);
 servo.write(i);
 delay(20);
 }
 for (i = 180; i > 0; i--) {
 Serial.println(i);
 servo.write(i);
 delay(20);
}
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
