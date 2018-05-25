int i = 0;
int led = 2;
void setup() {
 Serial.begin(19200);
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 pinMode(led,INPUT);
}
void loop() {
tone(2, 440);
tone(2, 277.18);
tone(2, 493.88);
delay(500);
noTone(2);

 i = i + 1;
 int value;
 
 value = analogRead(A0);
 value = analogRead(A1);
 value = analogRead(A2);
 Serial.print(value);
 Serial.println(" 0 1023");
 Serial.print(value);
 Serial.println(" 0 1023");
 Serial.print(value);
 Serial.println(" 0 1023");
}

