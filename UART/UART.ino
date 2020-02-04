void setup() {
  Serial.begin(9600); // start UART
}

void loop() {
  if(Serial.available()) { // enter function if data is on UART buffer
    char c = Serial.read(); // read data from buffer
    Serial.write(c); // write data on UART channel
  }
}
