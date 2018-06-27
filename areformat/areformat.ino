#include <IRremote.h>
#include <Servo.h>
int led = 13;
int RECV_PIN = 4;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 2;
int BIN2 = 12;
int servoPin = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;
int val;  

void setup() {
  Serial.begin(19200);
  servo.attach(servoPin);
  irrecv.enableIRIn();
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
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

void loop()
{
  int value;
  value = analogRead(A0);
  Serial.print(value);
  Serial.println("57 0 1023");

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  if (irrecv.decode(&results)) {
    if (results.value == 0x10EFA05F) {
      Serial.println("Button Up");
      digitalWrite(led, HIGH);
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      forward();
      delay(2000);
    }
    else if (results.value == 0x10EF00FF) {
      Serial.println("Button Down");
      digitalWrite(led, HIGH);
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      backward();
      delay(2000);
    }
    else if (results.value == 0x10EF20DF) {
      Serial.println("Button Right");
      digitalWrite(led, HIGH);
      digitalWrite(AIN1, HIGH);
      digitalWrite(AIN2, LOW);
      digitalWrite(BIN1, HIGH);
      digitalWrite(BIN2, LOW);
      stop();
      delay(1000);
    }
    else if (results.value == 0x10EF10EF) {
      Serial.println("Button Left");
    }
    else {
      Serial.print("Unrecognized: ");
      Serial.print(results.value, HEX);
      Serial.println();
    }
    irrecv.resume(); // Receive the next value
  }
  int i;
  value = analogRead(A0);
  value = analogRead(A1);
  Serial.print(value);
  Serial.println("0,1023,0,180");
  for (i = 109; i < 180; i++) {
    Serial.println("0, 1023, 0, 180");
    servo.write(value);
    delay(20);
  }
  for (i = 53; i < 180; i++) {
    Serial.println(i);
    servo.write(i);
    delay(20);
  }
  for (i = 180; i > 0; i--) {
    Serial.println(value);
    servo.write(value);
    delay(20);
  }

}

