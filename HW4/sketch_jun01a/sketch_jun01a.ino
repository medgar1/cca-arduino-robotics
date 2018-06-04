#include <IRremote.h>
int RECV_PIN = 4;
int led = 13;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 12;
int BIN2 = 4;
int i = 0;
int b = 1;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(19200);
  Serial.println("startup");
  Serial.begin(19200);
  irrecv.enableIRIn();
  pinMode(A0, INPUT);
  pinMode(led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  }
  

void forward() {
  digitalWrite(led, HIGH);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
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
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
void loop() 
  {
if (b < 10) {
digitalWrite(13,HIGH);
  }
  
else if (b < 20) {
digitalWrite(13,HIGH);
}

  else {
    digitalWrite(13,LOW);
  }
  {
 if (irrecv.decode(&results)) {
 Serial.println(results.value, HEX);
 irrecv.resume(); // Receive the next value
 }
 if (irrecv.decode(&results)) {
 if (results.value == 0x90) {
 Serial.println("Button Up");
 }
 else if (results.value == 0x890) {
 Serial.println("Button Down");
 }
 else if (results.value == 0x490) {
 Serial.println("Button Right");{
 }
 }else if (results.value == 0xC90) {
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
}

