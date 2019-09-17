#include "drive.h"
#include "declarations.h"

void setMotorSpeed(DriveSide side, int speed) {
  if(side == DriveSide::LEFT) {
    MOTOR_BACK_LEFT.spin(directionType::fwd, 127, velocityUnits::dps);
    MOTOR_FRONT_LEFT.spin(directionType::fwd, 127, velocityUnits::dps);
  } else if (side == DriveSide::RIGHT) {
    MOTOR_BACK_RIGHT.spin(directionType::fwd, 127, velocityUnits::dps);
    MOTOR_FRONT_RIGHT.spin(directionType::fwd, 127, velocityUnits::dps);
  }
}

void arcadeDrive() {
  int leftX = axisValue(MASTER.Axis4);
  int leftY = axisValue(MASTER.Axis3);
  int speedLeft = abs(leftX + leftY) > THRESHOLD? leftX + leftY: 0;
  int speedRight = abs(leftX - leftY) > THRESHOLD? leftX - leftY: 0;
  setMotorSpeed(DriveSide::LEFT, speedLeft);
  setMotorSpeed(DriveSide::RIGHT, speedRight);

}