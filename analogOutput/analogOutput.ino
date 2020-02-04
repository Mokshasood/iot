int val;

void setup() {
  pinMode(10, OUTPUT); // set pin 10 as output
  val = 0; // set val variable to 0
}

void loop() {
  if(val > 255) val = 0; // if val is higher than 255 (8-bits), reset
  analogWrite(10, val); // set analog value on pin 10
  val += 10; // increment val
  delay(100);
}
