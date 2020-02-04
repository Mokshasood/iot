void setup() {
  pinMode(12, INPUT); // Settine the pin 12 to INPUT
//  digitalWrite(12, LOW); // this line is optional
  pinMode(13, OUTPUT); // Setting the pin 13 to OUTPUT
}

void loop() {
  bool data = digitalRead(12); // reading from pin 12
  digitalWrite(13, !data); // write inverted data on pin 13
}
