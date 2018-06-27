#include <IRremote.h>
#include <Servo.h>
int led = 13;
int RECV_PIN = 4;
int AIN1 = 8;
int AIN2 = 7;
int BIN1 = 9;
int BIN2 = 10;
int servoPin = 11;

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo servo;
int photocellPin = A0;     //define photo cell reading input
int photocellReading;     //define photo cell reading variable
int val;

void setup() {
  Serial.begin(19200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  servo.attach(servoPin);
  pinMode(led, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  irrecv.enableIRIn();
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
  value = analogRead(A1);
  value = analogRead(A2);
  value = analogRead(A3);
  value = analogRead(A4);
  value = analogRead(A5);
  Serial.print(value);
  Serial.println(" 0 1023");
  if (value <= 180)   {                 //if the LDR is showing darkness
    value = analogRead(A0);
    servo.write(110);                          //then tell the servo to rotate forwards at a steady rate (close shade)
    delay(2500);                               //2.5 second delay while shade is closing?
    servo.write(90);                         //stop rotation after dalay
  }
  else if (value >= 180)         {     //if the LDR is showing light
    servo.write(70);                           //then tell the servo to rotate backwards at a steady rate (open shade)
    delay(2500);                               //2.5 second delay while shade is opening?
    servo.write(90);                         //stop rotation after dalay
  }
  else if (value >= 90 && value <= 109) {
    servo.write(90);
  }

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
    else if (results.value == 0xDDCBDAED) {
      Serial.println("Button Left");
      stop();
      delay(1000);
    }
    else {
      Serial.print("results.value == 0x6ADBBDCF)");
      Serial.print(results.value, HEX);
      Serial.println("loop");

    }
    irrecv.resume(); // Receive the next value
  }
}

