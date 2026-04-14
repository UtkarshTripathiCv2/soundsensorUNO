int soundPin = 2;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sound = digitalRead(soundPin);
  if(sound == LOW) {
    Serial.println("Sound Not Detected");
    digitalWrite(4,LOW);
  } else {
    Serial.println("Sound Detected");
    digitalWrite(4,HIGH);
  }
  
  delay(200);
}
