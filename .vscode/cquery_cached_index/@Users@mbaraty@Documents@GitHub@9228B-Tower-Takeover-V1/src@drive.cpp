#include "drive.h"
#include "declarations.h"


void drive() {
  setSideSpeed(DriveSide::LEFT, 80);
  setSideSpeed(DriveSide::RIGHT, 80);
  
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
  int leftX = axisValue(MASTER.Axis2);
  int leftY = axisValue(MASTER.Axis3);
  int speedLeft = abs(leftX - leftY) > THRESHOLD? leftX - leftY: 0;
  int speedRight = abs(leftX + leftY) > THRESHOLD? leftX + leftY: 0;
  setSideSpeed(DriveSide::LEFT, speedLeft);
  setSideSpeed(DriveSide::RIGHT, speedRight);
}

void tankDrive() {
  int leftY = axisValue(MASTER.Axis1);
  int rightY = axisValue(MASTER.Axis3);
  int speedLeft = abs(leftY) > THRESHOLD? -leftY: 0;
  int speedRight = abs(rightY) > THRESHOLD? rightY: 0;
  setSideSpeed(DriveSide::LEFT, speedLeft);
  setSideSpeed(DriveSide::RIGHT, speedRight);
}

void moveStackForward() {
  double final = 1000; 
  MOTOR_STACK.startRotateTo(final, rotationUnits::deg);
}

void moveStackBack() {
  double final = -1000;
  MOTOR_STACK.startRotateTo(final, rotationUnits::deg); 
}

void stackControl() {
  if(buttonIsPressed(MASTER.ButtonX)) 
    moveStackForward();
  else if(buttonIsPressed(MASTER.ButtonA))
    moveStackBack();
}

