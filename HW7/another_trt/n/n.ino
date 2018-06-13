int distanceThreshold = 7;
int sensorResetTime = 60;
int rightTurnTime = 250;
int robotState = 0;
unsigned long robotTimer;
void RobotSM()
{
 float inches;

 // Forward
 if (robotState == 0) {
 forward();
 robotState++;
 }
 // Scan
 else if (robotState == 1) {
 inches = ping();
 if (inches > distanceThreshold) {
 robotState = 3;
 }
 else {
 robotTimer = millis();
 robotState = 2;
 }
 }
 // Wait for sensor
 else if (robotState == 2) {
 if (millis() - robotTimer > sensorResetTime) {
 robotState = 1;
 }
 }
 // Stop
 else if (robotState == 3) {
 stop();
 robotState++;
 }
 // Right
 else if (robotState == 4) {
 right();
 robotTimer = millis();
 robotState++;
 }
 // Wait
 else if (robotState == 5) {
 if (millis() - robotTimer > rightTurnTime) {
 robotState++;
 }
 }
 // Stop 2
 else if (robotState == 6) {
 stop();
 robotState++;
 }

 // Scan 2
 else if (robotState == 7) {
 inches = ping();
 if (inches > distanceThreshold) {
 robotTimer = millis();
 robotState++;
 }
 else {
 robotState = 4;
 }
 }
 // Wait for sensor 2
 else if (robotState == 8) {
 if (millis() - robotTimer > sensorResetTime) {
 robotState = 0;
 }
 }
}
