/**
 * To view the output, connect Arduino to PC and open Serial Plotter
 */

#include <Wire.h>
float GyroX, GyroY, GyroZ;
float angleX, angleY, angleZ;
long previousTime, currentTime, elapsedTime;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission(true);
  angleX = 0;
  angleY = 0;
  angleZ = 0;
}

void loop() {
  previousTime = millis();        // Previous time is stored before the actual time read
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);
  currentTime = millis();            // Current time actual time read
  elapsedTime = (currentTime - previousTime);
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  angleX = angleX + (GyroX * elapsedTime);
  angleY = angleY + (GyroY * elapsedTime);
  angleZ = angleZ + (GyroZ * elapsedTime);
  Serial.println("X Y Z");
  Serial.print(angleX);
  Serial.print(" ");
  Serial.print(angleY);
  Serial.print(" ");
  Serial.println(angleZ);
}
