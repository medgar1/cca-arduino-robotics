#include <IRremote.h>
int led = 9;
int button = 5;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 12;
int BIN2 = 4;
int pot = A0;
int motorPWM = 9;
int i = 0;
int triggerPin = 10;
int echoPin = 11;
bool wasPressed = false;
bool ledState = false;
const int RECV_PIN = 2;



IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
 Serial.begin(19200);
 irrecv.enableIRIn();
 irrecv.blink13(true);
 pinMode(led, OUTPUT);
 pinMode(button, INPUT_PULLUP);
 pinMode(pot, INPUT);
 pinMode(AIN1, OUTPUT);
 pinMode(AIN2, OUTPUT);
 pinMode(BIN1, OUTPUT);
 pinMode(BIN2, OUTPUT);
 pinMode(triggerPin, OUTPUT);
 pinMode(echoPin, INPUT);
 digitalWrite(triggerPin, LOW);
 
}

void forward(int howFast) {
 digitalWrite(AIN1, HIGH);
 digitalWrite(AIN2, LOW);
 digitalWrite(BIN1, HIGH);
 digitalWrite(BIN2, LOW);
 analogWrite(motorPWM, howFast);
}

void backward() {
 digitalWrite(led, HIGH);
 digitalWrite(AIN1, LOW);
 digitalWrite(AIN2, HIGH);
 digitalWrite(BIN1, HIGH);
 digitalWrite(BIN2, LOW);
}

void stop() {
 digitalWrite(led, LOW);
 digitalWrite(AIN1, LOW);
 Serial.println("Button Up");
 digitalWrite(AIN2, LOW);
 digitalWrite(BIN1, LOW);
 digitalWrite(BIN2, LOW);
}
void loop() 

{
 float inches = ping();
 Serial.println(inches);
 delay(60);
}
{
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
}

{
 if (digitalRead(button) == LOW) {
 if (! wasPressed) {
 Serial.println("Button pressed");
 wasPressed = true;
 ledState = !ledState;
 digitalWrite(led, ledState);
 }
 }
 else {
 if (wasPressed) {
 Serial.println("Button released");
 Serial.println();
 wasPressed = false;;
 }
 }{
  
 char c = Serial.read();
 if (c == 'y') {
 digitalWrite(led, HIGH);
 Serial.println("I turned the LED on");
 }
 {
 
 int val;
 val = analogRead(pot);
 // analogRead() values go from 0 to 1023,
 // analogWrite() values are from 0 to 255
 analogWrite(led, 200/4);
}
  {
 analogWrite(led, 128); // 50% brightness
}

{
 if (digitalRead(button) == LOW) {
 Serial.println("Button pressed");
 digitalWrite(led, HIGH);
 }
 else {
 Serial.println("Button not pressed");
 digitalWrite(led, LOW);
 }
}

 if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
 }

 if (c == 'n') {
 digitalWrite(led, LOW);
 Serial.println("I turned the LED off");
 }

if (irrecv.decode(&results)) {
}
 if (results.value == 0x90) {
 Serial.println("Button Up");
 }

 else if (results.value == 0x890) {
 Serial.println("Button Down");
 }
 
 else if (results.value == 0x490) {
 Serial.println("Button Right");
 }
 
 else if (results.value == 0xC90) {
 Serial.println("Button Left");
 }
 else {
 Serial.print("Unrecognized: ");
 Serial.print(results.value, HEX);
 Serial.println();
 }

 
 if (digitalRead(button) == LOW) {
 if (! wasPressed) {
 Serial.println("Button pressed");
 wasPressed = true;
 }
 }
 else {
 if (wasPressed) {
 Serial.println("Button released");
 Serial.println();
 wasPressed = false;;
 }
 }
}

 int i = 0;
 while (i < 3)
 digitalWrite(AIN1, HIGH);
 delay(100);
 backward();
 digitalWrite(AIN2, LOW);
 delay(100);
 backward();
 delay(2000);
 stop();
 digitalWrite(BIN1, HIGH);
 delay(100);
 backward();
 digitalWrite(BIN2, LOW);
 delay(100);
 backward();
 delay(2000);
 stop();
 i++;
 irrecv.resume(); // Receive the next value
}
{
float ping() {
 unsigned long maxTime = 20000;
 unsigned long us;
 float inches;

