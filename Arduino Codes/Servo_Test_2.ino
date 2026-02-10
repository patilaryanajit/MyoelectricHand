#include <ESP32Servo.h>

Servo servo;

void setup() {
  servo.attach(23);   // GPIO 2
}

void loop() {
  servo.write(180); // Spin one direction (max speed)
  delay(3000);      // 3 seconds
  servo.write(0); // Spin one direction (max speed)
  delay(3000);      // 3 seconds

}
