// UGA Bulldog Biomechanics Club
// Arduino driver code to read EMG sensor data
// Great diagnostic tool to check if an EMG Sensor is working!

// Author - Aryan Patil
// Date Last Updated - April 4 2026

// Update Log - 
// No updates yet, (low cortisol) :)

// Connect SIG (or Signal, depends on EMG sensor) pin on EMG Sensor to A5 on the arduino board please! 
// Also remember to connect the board to sensor ground (NOT Virtual Ground, unless you like smoke)
// If you don't know what virtual ground is please don't touch the wires on the board (ask help from an expert instead)
const int sensorPin = A5;

// Variables for exact timing
unsigned long previousMicros = 0;
const unsigned long sampleInterval = 1000; // 1000 microseconds = 1 kHz

void setup() {
  Serial.begin(500000); 
}

void loop() {
  unsigned long currentMicros = micros();

  // Check if exactly 1000 microseconds have passed
  if (currentMicros - previousMicros >= sampleInterval) {
    
    // Add interval to previous time to prevent drift over time
    previousMicros += sampleInterval; 

    // Read sensor
    int sensorValue = analogRead(sensorPin);

    // Calculate voltage
    float voltage = sensorValue * (5.0 / 1023.0);

    // Print data
    Serial.print("Min:0,");
    Serial.print("Max:5,");
    Serial.print("Voltage:");
    Serial.println(voltage);
  }
  
  // Heyy, you are doing great, YOU GOT THIS, keep up the good work gang! :) - AP

}

