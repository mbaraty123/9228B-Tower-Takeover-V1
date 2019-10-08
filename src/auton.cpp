#include "auton.h"
#include "drive.h"
#include "declarations.h"

void moveForward(double inches, int velocity) {
  double rotations = ROTATIONS_PER_INCH * inches;

  moveFor(rotations, velocity);
}

void moveFor(double rotations, int velocity) {
  MOTOR_BACK_LEFT.spinFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct);
  MOTOR_BACK_RIGHT.spinFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct);
  MOTOR_FRONT_LEFT.spinFor(rotations, rotationUnits::rev, velocity, velocityUnits::pct);
  MOTOR_FRONT_RIGHT.spinFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
}

