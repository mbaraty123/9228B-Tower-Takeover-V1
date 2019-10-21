#include "auton.h"
#include "drive.h"
#include "declarations.h"

void moveForward(double inches) {
  double time = inches * (476.19)/9;

  MOTOR_BACK_LEFT.spin(directionType::fwd, 100, velocityUnits::rpm);
  MOTOR_FRONT_LEFT.spin(directionType::fwd, 100, velocityUnits::rpm);
  MOTOR_BACK_RIGHT.spin(directionType::rev, 100, velocityUnits::rpm);
  MOTOR_FRONT_RIGHT.spin(directionType::rev, 100, velocityUnits::rpm);
  
  vexDelay(time);

  MOTOR_BACK_LEFT.stop(brakeType::hold);
  MOTOR_FRONT_LEFT.stop(brakeType::hold);
  MOTOR_BACK_RIGHT.stop(brakeType::hold);
  MOTOR_FRONT_RIGHT.stop(brakeType::hold);
}

