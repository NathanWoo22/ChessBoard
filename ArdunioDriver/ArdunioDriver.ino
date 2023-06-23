#include <AccelStepper.h>

// Define the first stepper motor
AccelStepper stepper1(1, 5, 2);
AccelStepper stepper2(1, 6, 4);

int speed1 = 300;
int speed2 = 300; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper1.setMaxSpeed(500);
  stepper2.setMaxSpeed(500);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    // get incoming bytees
    String readstring = Serial.readString();
    speed1 = readstring.toInt();
    Serial.println(speed1);
    if (speed1 == 1){
      Serial.print("should be exiting");
      exit(0);
      Serial.print("Obviously not exiting");
    }
    delay(1000);
  }

  else{
    stepper1.setSpeed(speed1);
    stepper1.runSpeed();
  
    stepper2.setSpeed(speed2);
    stepper2.runSpeed();
  }
}
