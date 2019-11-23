#include "drive.h"
#include "declarations.h"
#include "auton.h"

bool slowMode = false;

void drive() {
  arcadeDrive();
  stackControl();
  armControl();
  intakeControl();

  if(buttonIsPressed(MASTER.ButtonUp)){
    slowMode = false;
  } else if(buttonIsPressed(MASTER.ButtonDown)){
    slowMode = true;
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
  else {
    MOTOR_FRONT_LEFT.spin(directionType::fwd, speed, velocityUnits::pct);
    MOTOR_FRONT_RIGHT.spin(directionType::fwd, speed, velocityUnits::pct);
    MOTOR_BACK_RIGHT.spin(directionType::fwd, speed, velocityUnits::pct);
    MOTOR_BACK_LEFT.spin(directionType::fwd, speed, velocityUnits::pct);
  }
}

void arcadeDrive() {
  int x = SPEED_MULTIPLIER  * -axisValue(MASTER.Axis1);
  int y = SPEED_MULTIPLIER * (.7  * (pow(-axisValue(MASTER.Axis3) / 9, 3) / 10));
  int speedLeft = abs(x + y) > THRESHOLD? -(x + y): 0;
  int speedRight = abs(x - y) > THRESHOLD? (x - y): 0;

  if(slowMode){
    setSideSpeed(DriveSide::LEFT, speedLeft / 3);
     setSideSpeed(DriveSide::RIGHT, speedRight / 3);
  } else {
    setSideSpeed(DriveSide::LEFT, speedLeft);
    setSideSpeed(DriveSide::RIGHT, speedRight);
  }
}

void tankDrive() {
  int l = SPEED_MULTIPLIER * (.7  * (pow(axisValue(MASTER.Axis3) / 9, 3) / 10));
  int r = SPEED_MULTIPLIER * (.7  * (pow(axisValue(MASTER.Axis2) / 9, 3) / 10));
  int speedLeft = abs(l) > THRESHOLD? l: 0;
  int speedRight = abs(r) > THRESHOLD? r: 0;
  
  if(slowMode){
    setSideSpeed(DriveSide::LEFT, speedLeft / 3);
     setSideSpeed(DriveSide::RIGHT, speedRight / 3);
  } else {
    setSideSpeed(DriveSide::LEFT, speedLeft);
    setSideSpeed(DriveSide::RIGHT, speedRight);
  }
}

void moveStackForward() {
  double final = 1.5; 
  MOTOR_STACK.startSpinTo(10, rotationUnits::rev, 30, velocityUnits::pct);
}

void moveStackBack() {
  double final = 0;
  MOTOR_STACK.startSpinTo(-10, rotationUnits::rev, 80, velocityUnits::pct); 
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
  MOTOR_ARM.startSpinTo(60.6, rotationUnits::rev, 100, velocityUnits::pct);
  //realValue 6.6
}

void armDown(){
  MOTOR_ARM.startSpinTo(-10, rotationUnits::rev, 100, velocityUnits::pct);
  //realValue 0
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
  if(!slowMode) {
    MOTOR_INTAKE_A.spin(directionType::fwd, 100, velocityUnits::pct);
    MOTOR_INTAKE_B.spin(directionType::fwd, 100, velocityUnits::pct);
  } else {
    MOTOR_INTAKE_A.spin(directionType::fwd, (100), velocityUnits::pct);
    MOTOR_INTAKE_B.spin(directionType::fwd, (100), velocityUnits::pct);
  }
}

void intakeOut() {
   if(!slowMode) {
    MOTOR_INTAKE_A.spin(directionType::rev, 100, velocityUnits::pct);
    MOTOR_INTAKE_B.spin(directionType::rev, 100, velocityUnits::pct);
  } else {
    MOTOR_INTAKE_A.spin(directionType::rev, .5*(100), velocityUnits::pct);
    MOTOR_INTAKE_B.spin(directionType::rev, .5*(100), velocityUnits::pct);
  }
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


