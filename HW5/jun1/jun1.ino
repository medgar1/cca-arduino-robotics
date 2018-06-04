#include <IRremote.h>
int RECV_PIN = 2;
int led = 13;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 12;
int BIN2 = 4;
int pot = A0;
int motorPWM = 13;
int button = 2;
int i = 0;
int b = 1;
bool wasPressed = false;

IRrecv irrecv(RECV_PIN);
decode_results results;



void setup() {
  Serial.begin(19200);
  irrecv.enableIRIn();
  Serial.println("run");

  pinMode(A0, INPUT);
  pinMode(led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
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
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void loop(){
int val;
val = analogRead(pot);
analogWrite(led, 128);
analogWrite(led, val/4);
}
{
 if (digitalRead(button) == LOW) {
 if (! wasPressed) {

 Serial.println("Button not pressed");
 digitalWrite(led, LOW);
 }


   if (irrecv.decode(&results)) {
    if (results.value == 0x90) {
      Serial.println("Button Up");{
 if (digitalRead(button) == LOW) {
 if (! wasPressed); 
 Serial.println("Button pressed");
 wasPressed = true;
 ledState = !ledState;
 digitalWrite(led, ledState);
 }

 else {
 if (wasPressed) {
 Serial.println("Button released");
 Serial.println();
 wasPressed = false;;
 }
 }
}

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
      Serial.print("Unrecognized:k");
      Serial.print(results.value, HEX);
      Serial.println();
    }
    irrecv.resume(); // Receive the next value
  }
}

