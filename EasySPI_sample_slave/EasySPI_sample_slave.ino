#include <EasySPI.h>


void setup() {
  Serial.begin(9600);
  EasySPI.begin(SLAVE,10);
}

void loop() {
  if(EasySPI.available()){
    while(EasySPI.available()){
      Serial.write(EasySPI.read());
    }
  }
  delay(1000);
}
