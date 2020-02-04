void func() { // func will be called on interrupt
  Serial.println('b'); // character 'b' will be printed
}
void setup() {
  pinMode(2,INPUT); // set pin 2 as input
  Serial.begin(9600); // start UART communication
  // set interrupt to be called on rising of pin voltage
  attachInterrupt(digitalPinToInterrupt(2), func, RISING); 
}

void loop() {
  Serial.println('a'); // character 'a' will be printed at interval of 1 second
  delay(1000);
}
