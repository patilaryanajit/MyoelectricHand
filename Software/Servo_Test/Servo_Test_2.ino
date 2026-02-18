#include <ESP32Servo.h>

Servo servo;

void setup() {
  servo.attach(23);   // GPIO 23
  Serial.begin(9600);
}

void loop() {
  servo.write(180); // Spin one direction (max speed)
  delay(2000);      // 3 seconds
  servo.write(0); // Spin one direction (max speed)
  delay(1000);      // 3 seconds'
  Serial.println("Working");
}
