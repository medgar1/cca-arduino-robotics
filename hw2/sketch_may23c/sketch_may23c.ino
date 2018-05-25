int led = 0;
int led2 = 0;

void setup() {
 Serial.begin(19200);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
}
void loop() {
 int value;
 value = analogRead(A0);
 value = analogRead(A1);
 Serial.print(value);
 Serial.print(led);
 Serial.println(" 0 1023 ");
}
