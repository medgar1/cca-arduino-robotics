int buttonBounceTime = 100;
int buttonState = 0;
unsigned long buttonTimer;
void buttonSM() {
 // State: Wait for press
 if (buttonState == 0) {
 if (digitalRead(buttonPin) == LOW) {
 buttonState++;
 buttonTimer = millis();
 }
 }
 // State: Wait for debounce time
 else if (buttonState == 1) {
 if (digitalRead(buttonPin) != LOW) {
 buttonState = 0;
 }
 else if (millis() - buttonTimer > buttonBounceTime) {
 buttonState++;
 }
 }
 // State: Fire
 else if (buttonState == 2) {
 // button is pressed!
 // do a thing!
 Serial.println("Button pressed!");
 buttonState++;
 }
 // State: Wait for release
 else if (buttonState == 3) {
 if (digitalRead(buttonPin) != LOW) {
 buttonState++;
 }
 }
 // State: Button released
 else if (buttonState == 4) {
 Serial.println("Button released!");
 buttonState = 0;
 }
}
