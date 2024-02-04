
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
