# Anti-Sleeping-Glasses
To addressing the issue of accidents caused by sleep fatigue among truck drivers, highlighting the urgency, impact, and potential solutions. Smart glasses which can be utilized to help truckers stay awake and alert while driving, thus reducing the risk of falling asleep at the wheel.

In response to the pressing concern of road accidents stemming from driver fatigue, we propose a solution :
Smart Glasses for Fatigue Prevention. This innovative wearable device aims to mitigate the risks associated with drowsy driving by proactively alerting drivers to signs of sleepiness, with help of sensors and buzzers.

Here is our code to control the arduino board:-

// Define pins
const int irSensorPin = 2;
const int buzzerPin = 3;
const int vibrationMotorPin = 4;

bool objectDetected = false;
unsigned long objectDetectedTime;
void setup() {
pinMode(irSensorPin, INPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(vibrationMotorPin, OUTPUT);
}

void loop() {
int irSensorValue = digitalRead(irSensorPin);

if (irSensorValue == LOW) {
if (!objectDetected) {

  objectDetected = true;
  objectDetectedTime = millis();
} else {
 
  if (millis() - objectDetectedTime >= 2000) {
 
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(vibrationMotorPin, HIGH);
  }
}
} else {

objectDetected = false;
digitalWrite(buzzerPin, LOW);
digitalWrite(vibrationMotorPin, LOW);
}
}
