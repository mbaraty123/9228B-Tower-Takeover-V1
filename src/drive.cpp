#include "drive.h"
#include "declarations.h"
#include "auton.h"


void drive() {
  tankDrive();
  stackControl();
  armControl();
  intakeControl();

  if(buttonIsPressed(MASTER.ButtonUp)){
    moveForward(1);
  }

}

void setSideSpeed(DriveSide side, int speed) {
  if(side == DriveSide::LEFT) {
    MOTOR_BACK_LEFT.spin(directionType::fwd, speed, velocityUnits::pct);
    MOTOR_FRONT_LEFT.spin(directionType::fwd, speed, velocityUnits::pct);
  } else if (side == DriveSide::RIGHT) {
    MOTOR_BACK_RIGHT.spin(directionType::fwd, speed, velocityUnits::pct);
    MOTOR_FRONT_RIGHT.spin(directionType::fwd, speed, velocityUnits::pct);
  }
}

void arcadeDrive() {
  int x = SPEED_MULTIPLIER  * /*(pow(-axisValue(MASTER.Axis1) / 10, 3) / 10)*/ -axisValue(MASTER.Axis1);
  int y = SPEED_MULTIPLIER * (.7  * (pow(-axisValue(MASTER.Axis3) / 9, 3) / 10)) /*-axisValue(MASTER.Axis3)*/;
  int speedLeft = abs(x + y) > THRESHOLD? -(x + y): 0;
  int speedRight = abs(x - y) > THRESHOLD? -(x - y): 0;

  setSideSpeed(DriveSide::LEFT, speedLeft);
  setSideSpeed(DriveSide::RIGHT, speedRight);
}

/* simple
void arcadeDrive() {
  int x = -axisValue(MASTER.Axis1); // get the current position on the x axis of the controller's right joystick
  int y = -axisValue(MASTER.Axis3); // get the current position on the y axis of the controller's left joystick

  int speedLeft = abs(x + y) > THRESHOLD? -(x + y): 0;
  int speedRight = abs(x - y) > THRESHOLD? -(x - y): 0;

  setSideSpeed(DriveSide::LEFT, speedLeft);
  setSideSpeed(DriveSide::RIGHT, speedRight);
}



*/
void tankDrive() {
  int l = SPEED_MULTIPLIER * (.7  * (pow(axisValue(MASTER.Axis3) / 9, 3) / 10));
  int r = SPEED_MULTIPLIER * (.7  * (pow(axisValue(MASTER.Axis2) / 9, 3) / 10));
  int speedLeft = abs(l) > THRESHOLD? l: 0;
  int speedRight = abs(r) > THRESHOLD? -r: 0;
  setSideSpeed(DriveSide::LEFT, speedLeft);
  setSideSpeed(DriveSide::RIGHT, speedRight);
}

void moveStackForward() {
  double final = 1.5; 
  MOTOR_STACK.startSpinTo(final, rotationUnits::rev, 30, velocityUnits::pct);
}

void moveStackBack() {
  double final = 0;
  MOTOR_STACK.startSpinTo(final, rotationUnits::rev, 80, velocityUnits::pct); 
}

void stackControl() {
  if(buttonIsPressed(MASTER.ButtonX)) 
    moveStackForward();
  else if(buttonIsPressed(MASTER.ButtonA))
    moveStackBack();
  else{
    MOTOR_STACK.stop(brakeType::brake);
  }
}

void armUp(){
  MOTOR_ARM.startSpinTo(2.1, rotationUnits::rev, 100, velocityUnits::pct);
}

void armDown(){
  MOTOR_ARM.startSpinTo(0.1, rotationUnits::rev, 100, velocityUnits::pct);
}

void armControl(){
  if(buttonIsPressed(MASTER.ButtonR1)){
    armUp();
  }
  else if (buttonIsPressed(MASTER.ButtonR2)) {
    armDown();
  }
  else {
    MOTOR_ARM.stop(brakeType::hold);
  }
}

void intakeIn() {
  MOTOR_INTAKE_A.spin(directionType::fwd, 70, velocityUnits::pct);
  MOTOR_INTAKE_B.spin(directionType::fwd, -70, velocityUnits::pct);
}

void intakeOut() {
  MOTOR_INTAKE_A.spin(directionType::rev, 70, velocityUnits::pct);
  MOTOR_INTAKE_B.spin(directionType::rev, -70, velocityUnits::pct);
}

void intakeControl() {
  if(buttonIsPressed(MASTER.ButtonL1)){
    intakeIn();
  }
  else if (buttonIsPressed(MASTER.ButtonL2)) {
    intakeOut();
  }
  else {
    MOTOR_INTAKE_A.stop(brakeType::hold);
    MOTOR_INTAKE_B.stop(brakeType::hold);
  }
}


