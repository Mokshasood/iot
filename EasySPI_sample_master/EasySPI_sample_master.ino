#include <EasySPI.h>

#define t 0

void setup() {
  EasySPI.begin(MASTER, 10);
}
 
void loop() {
  EasySPI.write('H');
  delay(t);
  EasySPI.write('e');
  delay(t);
  EasySPI.write('l');
  delay(t);
  EasySPI.write('l');
  delay(t);
  EasySPI.write('o');
  delay(t);
  EasySPI.write('!');
  delay(t);
  EasySPI.write('\n');
  delay(1000);
}
