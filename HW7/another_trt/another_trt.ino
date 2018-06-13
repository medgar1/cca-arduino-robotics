int ledPin = 13;
int ledOnTime = 1000;
int ledOffTime = 500;
int ledState = 0;
unsigned long ledTimer;
void ledSM() {
 // State: TurnOn
 if (ledState == 0) {
 digitalWrite(ledPin, HIGH);
 ledTimer = millis();
 ledState++;
 }
 // State: Wait 1
 else if (ledState == 1) {
 if (millis() - ledTimer > ledOnTime) {
 ledState++;
 }
 }
 // State: Turn Off
 else if (ledState == 2) {
 digitalWrite(ledPin, LOW);
 ledTimer = millis();
 ledState++;
 }
 // State: Wait 2
 else if (ledState == 3) {
 if (millis() - ledTimer > ledOffTime) {
 ledState = 0;
 }
 }
}
void setup() {
 pinMode(ledPin, OUTPUT);
}
void loop() {
 ledSM();
}
