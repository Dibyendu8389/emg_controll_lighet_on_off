int emgPin = A0;       // EMG sensor input
int relayPin = 7;      // Relay module connected to pin 7
int threshold = 60;    // Threshold value

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Relay OFF at start
  Serial.begin(9600);
}

void loop() {
  int emgValue = analogRead(emgPin);  // Read EMG value
  Serial.println(emgValue);

  if (emgValue > threshold) {
    digitalWrite(relayPin, HIGH);   // Turn ON relay
  } else {
    digitalWrite(relayPin, LOW);    // Turn OFF relay
  }

  delay(50); // Small delay to stabilize readings
}
