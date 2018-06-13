int triggerPin = 8;
int echoPin = 7;
int led = 9;
int pot = A0;
int AIN1 = 6;
int AIN2 = 12;
int BIN1 = 5;
int BIN2 = 4;
int motorPWM = 10;

void setup()  {
  Serial.begin(19200);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
}

void loop() {
 int val;
 val = analogRead(pot);
 analogWrite(led, val/4);
 analogWrite(100, 128);
 analogWrite(100, 200/4);
 Serial.println("inches");
 delay(60);
}

void forward(int howFast) {
 digitalWrite(AIN1, HIGH);
 digitalWrite(AIN2, LOW);
 digitalWrite(BIN1, HIGH);
 digitalWrite(BIN2, LOW);
 analogWrite(motorPWM, howFast);
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
