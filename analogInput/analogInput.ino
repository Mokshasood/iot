void setup() {
  Serial.begin(9600); // start UART communication
  pinMode(A0, INPUT); // set pin A0 as input
}

void loop() {
  int data = analogRead(A0); // reading from pin A0
  Serial.println(data); // print data on UART channel
}
