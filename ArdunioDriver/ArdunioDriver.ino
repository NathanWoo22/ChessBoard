#include <AccelStepper.h>

// Define the first stepper motor
AccelStepper stepper1(1, 5, 2);
AccelStepper stepper2(1, 6, 4);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper1.setMaxSpeed(500);
  stepper2.setMaxSpeed(500);

}

void loop() {
  // put your main code here, to run repeatedly:

  stepper1.setSpeed(500);
  stepper1.runSpeed();
 
  stepper2.setSpeed(500);
  stepper2.runSpeed();

  if (Serial.available() > 0) {
    // get incoming byte:
    int x = Serial.readString().toInt();
    Serial.print(x);
    exit(0);
  }
}
