#include <Servo.h>
int i = 0;
int triggerPin = 8;
int servoPin = 2;
int echoPin = 7;
int led = 9;
int pot = A0;
int AIN1 = 6;
int AIN2 = 5;

Servo servo;
// i dont want to start back from scratch but i'm losing my damn mind

void setup()  {
  Serial.begin(19200);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  servo.attach(servoPin);
}

void forward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
}
void backward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
}

void stop() {
  digitalWrite(led, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
}


void loop() {
  int val;
  i = i + 1;
  Serial.println("the value is..");
  Serial.println(i);
  val = analogRead(pot);
  analogWrite(led, val / 4);
  analogWrite(100, 128);
  analogWrite(100, 200 / 4);
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
