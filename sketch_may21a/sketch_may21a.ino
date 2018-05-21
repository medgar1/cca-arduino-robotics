int led = 13;
int led2 = 10;
int led3 = 11;
void setup() {
 pinMode(led, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
}
void loop() {
 digitalWrite(led, HIGH);
 delay(20);
 digitalWrite(led, LOW);
 delay(05);
  digitalWrite(led2, HIGH);
 delay(05);
 digitalWrite(led2, LOW);
 delay(05);
  digitalWrite(led3, HIGH);
 delay(05);
 digitalWrite(led3, LOW);
 delay(05);
}



