// Pin Definitions
const int soundSensorPin = 2; // Digital Output (DO) from sensor
const int relayPin = 4;      // Pin connected to Light/Relay (or built-in LED)

// Variables
bool lightState = false;      // Keeps track of whether light is ON or OFF
unsigned long lastTrigger = 0; // For debouncing
const int delayTime = 500;    // 500ms lockout (prevents double-triggering)

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(relayPin, LOW); // Start with light off
}

void loop() {
  int sensorValue = digitalRead(soundSensorPin);

  // Sound sensors usually output LOW when sound is detected
  if (sensorValue == LOW) {
    
    // Check if enough time has passed since the last clap (Debounce)
    if (millis() - lastTrigger > delayTime) {
      lightState = !lightState;        // Flip the state (ON to OFF, or OFF to ON)
      digitalWrite(relayPin, lightState);
      
      Serial.print("Clap Detected! Light is now: ");
      Serial.println(lightState ? "ON" : "OFF");

      lastTrigger = millis();          // Update the last trigger time
    }
  }
}
