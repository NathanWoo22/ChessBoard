#include <AccelStepper.h>

// Define the first stepper motor
AccelStepper stepper1(1, 5, 2);
AccelStepper stepper2(1, 6, 4);

int speed1 = 300;
int speed2 = 300; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);

  // Initialize current position in case it is necessary
  stepper1.setCurrentPosition(stepper1.currentPosition());
  stepper2.setCurrentPosition(stepper2.currentPosition());
}

void loop() {
  // stepper1.moveTo(100);
  //put your main code here, to run repeatedly:

  if (Serial.available()) {
    // get incoming bytees
    String readstring = Serial.readString();
    int newLocation = readstring.toInt();
    Serial.println(newLocation);
    driveTo(newLocation, stepper2);
    if (newLocation == 0){
      Serial.print("should be exiting");
      exit(0);
      Serial.print("Obviously not exiting");
    }
    delay(1000);
  }

  else{
    delay(100);
  }
}

void driveTo(int position, AccelStepper stepper){
  int kp = 2;
  int kd = 0.4;
  int speed = 0;
  while(abs(position - stepper.currentPosition()) > 0){
    // PD variable
    speed = kp * (position - stepper.currentPosition()) - kd * speed;
    stepper.setSpeed(speed);
    stepper.runSpeed(); 
    Serial.println(stepper.currentPosition());
  }
}
