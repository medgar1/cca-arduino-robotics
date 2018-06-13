#include <Servo.h>
#include <IRremote.h>
int foo;
foo = 3 + 7; // 10
foo = 5 * 4; // 20
foo = 5 + 5 * 4; // 25
foo = (5 + 5) * 4; // 40
foo = foo + 10; // 50
foo += 10; // 60
foo -= 15; // 45
foo++; /

int servoPin = 2;
Servo servo;
void setup() {
 servo.attach(servoPin);
}

  void loop() {
 servo.write(0);
 delay(1000);
 servo.write(90);
 delay(1000);

 servo.write(180);
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
