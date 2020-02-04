void setup() {
  pinMode(13, OUTPUT); // Setting the pin 13 to OUTPUT
}

void loop() {
  digitalWrite(13, HIGH); // Pin 13 will turn the internal led on
  delay(1000);
  digitalWrite(13, LOW); // Pin 13 will turn the internal led off
  delay(1000);
}
