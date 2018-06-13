#include <IRremote.h>
int b = 1;
int led = 4;
int pot = A0;
int motorPWM = 9;
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(19200);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  int i = 0;
  int val;
  val = analogRead(pot);
  // analogRead() values go from 0 to 1023,
  // analogWrite() values are from 0 to 255
  analogWrite(led, val / 4);

  while (i < 3)
  {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
    i++;
  }
  delay(1500);
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  if (irrecv.decode(&results)) {
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
    irrecv.resume(); // Receive the next value
  }
  if (b == 1) {
    digitalWrite(led, HIGH);
    b = 0;
  }
  else {
    digitalWrite(led, LOW);
    delay(500);
  }

}

void forward(int howFast) {
 digitalWrite(AIN1, HIGH);
 digitalWrite(AIN2, LOW);
 digitalWrite(BIN1, HIGH);
 digitalWrite(BIN2, LOW);
 analogWrite(motorPWM, howFast);
}

