#include <Servo.h>
#include <IRremote.h>

int led = 13;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 4;
int BIN2 = 12;
int triggerPin = 10;
int echoPin = 9;
int servo1pin = 2;
int servo2pin = 3;
int foo;
int b = 1;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo1;
Servo servo2;
Servo servo;



void setup() {
  Serial.begin(19200);
  irrecv.enableIRIn();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);

  pinMode(BIN2, OUTPUT);
}

void forward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}
void backward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}
void stop() {
  digitalWrite(led, LOW);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void loop() {

  pinMode(led, OUTPUT);
  delay(60);
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
}

int i = 0;
while (i < 3)
{
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  delay(100);
  i++;
}

{
  if (irrecv.decode(&results)) {
    if (results.value == 0x26) {
      Serial.println("Button Up");
    }
    else if (results.value == 0x25) {
      Serial.println("Button Down");
    }
    else if (results.value == 0x23) {
      Serial.println("Button Right");
    }
    else if (results.value == 0x22) {
      Serial.println("Button Left");
    }
    else {
      Serial.print("Unrecognized: ");
      Serial.print(results.value, HEX);
      Serial.println();
    }
    irrecv.resume(); // Receive the next value
  }
}
{
  int i;
  for (i = 0; i < 3; i++)
  {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
  delay(1500);
}
{
  if (b == 1) {
    digitalWrite(led, HIGH);
    b = 0;
  }
  else {
    digitalWrite(led, LOW);
    b = 1;
  }
  delay(500);
}
{
  int value;
  value = analogRead(A0);
  value = analogRead(A1);
  Serial.print(value);
}
{
  char c = Serial.read();
  if (c == 'y') {
    digitalWrite(led, HIGH);
    Serial.println("I turned the LED on");
  }
  if (c == 'n') {
    digitalWrite(led, LOW);
    Serial.println("I turned the LED off");
  }
  delay(1500);
}
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}
forward();
delay(2000);
backward();
delay(2000);
stop();
delay(1000);
}

float ping() {
  unsigned long maxTime = 20000;
  unsigned long us;
  float inches;
  // Hold triggerPin high for at least 10us
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  // Measure length of high pulse on echoPin
  us = pulseIn(echoPin, HIGH, maxTime);
  // pulseIn returns 0 on timeout. Assume worst case.
  if (us == 0) {
    us = maxTime;
  }
  // Convert roundtrip microseconds to inches
  inches = us * 0.013504 / 2;
  return inches;
}

