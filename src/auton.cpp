#include "auton.h"
#include "drive.h"
#include "declarations.h"

void moveForward(double inches) {
  /*double time = (sqrt(inches) * MSEC_PER_INCH / 2) - (MSEC_PER_INCH/2) - MSEC_PER_INCH;

  MOTOR_BACK_LEFT.spin(directionType::fwd, 50, velocityUnits::rpm);
  MOTOR_FRONT_LEFT.spin(directionType::fwd, 50, velocityUnits::rpm);
  MOTOR_BACK_RIGHT.spin(directionType::rev, 50, velocityUnits::rpm);
  MOTOR_FRONT_RIGHT.spin(directionType::rev, 50, velocityUnits::rpm);
  vexDelay(time);

  MOTOR_BACK_LEFT.stop(brakeType::hold);
  MOTOR_FRONT_LEFT.stop(brakeType::brake);
  MOTOR_BACK_RIGHT.stop(brakeType::hold);
  MOTOR_FRONT_RIGHT.stop(brakeType::brake);*/

  double rotations = inches * ROTATIONS_PER_INCH;

  MOTOR_BACK_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_BACK_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
}

void pivotClockwise(float degrees) {
  double rotations_per_360 = 1.11;
  double rotations = rotations_per_360 * (degrees / 360);

  MOTOR_BACK_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_BACK_RIGHT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
  MOTOR_FRONT_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_RIGHT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
}

void pivotCounterClockwise(float degrees) {
  double rotations_per_360 = 1.11;
  double rotations = rotations_per_360 * (degrees / 360);

  MOTOR_BACK_LEFT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
  MOTOR_BACK_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_LEFT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
  MOTOR_FRONT_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
}