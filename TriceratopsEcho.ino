// Talking Triceratops Skull Code

// Note that this is for Adafruit Motor Shield v1
// The new version (v2) may use different code!

#include <AFMotor.h>
int SoundInPin = A0;

AF_DCMotor motor(2);

void setup() {
  //Serial.begin(9600); // To see sensor values for debugging

  // Initialize Motor
  motor.setSpeed(100);
  motor.run(RELEASE);
  pinMode(SoundInPin, INPUT); 
  
}

void loop() {
  uint8_t i;
  
  // Read the input from the Amazon Echo Audio (interface required!)
  int sensorValue = analogRead(SoundInPin);
  
  //Serial.println(sensorValue); // For debugging purposes

  //If audio is detected, move the motor backwards then forward
  //Polarity of motor connection matters here - you might need to switch these
  
  if (sensorValue > 30) { // This value may require tweaking!
    delay(1);

    // The forward/backwards values depend on motor speed, and aren't too critical
    // Tweak for desired performance
    motor.run(BACKWARD);
    delay(150);
    motor.run(FORWARD);
    delay(80);
  
  }
  // Stop moving the motor
  motor.run(RELEASE);  
}
