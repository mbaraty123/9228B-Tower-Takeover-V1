#include "auton.h"
#include "drive.h"
#include "declarations.h"

void moveForward(double inches) {
  double rotations = inches * ROTATIONS_PER_INCH;

  MOTOR_BACK_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_BACK_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
}

void pivotClockwise(float degrees) {
  double rotations_per_360 = 6.55;
  double rotations = rotations_per_360 * (360 / degrees);

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

/**
  * @brief the autonomous switcher
  * @author Michael Baraty
  */
void auton(Side side, Color color) {
  autonStart();

  if(color == Color::BLUE && side == Side::LEFT)
    autonBlueLeft();
  else if (color == Color::BLUE && side == Side::RIGHT)
    autonBlueLeft();
  else if (color == Color::RED && side == Side::LEFT)
    autonRedLeft();
  else if (color == Color::RED && side == Side::RIGHT)
    autonRedRight();
}


void autonBlueLeft(){
  MOTOR_INTAKE_A.startRotateFor(6, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(6, rotationUnits::rev, 100, velocityUnits::pct);

  moveForward(30);

  pivotClockwise(180);

  moveForward(30);

  pivotClockwise(90);

  moveForward(18);

  moveStackForward();

  intakeOut();

  moveForward(-5);

  MOTOR_INTAKE_A.stop();
  MOTOR_INTAKE_B.stop();
}

void autonBlueRight(){
  //run intakes
  //move forward 30
  //cut intakes
  //180
  //move 30
  //90 counterclockwise
  //forward 40
  //drop stack somehow
}

void autonRedLeft(){
  //run intakes
  //move forward 30
  //cut intakes
  //180
  //move 30
  //90 clockwise
  //forward 40
  //drop stack somehow
}

void autonRedRight(){
  MOTOR_INTAKE_A.startRotateFor(6, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(6, rotationUnits::rev, 100, velocityUnits::pct);

  moveForward(30);

  pivotClockwise(180);

  moveForward(30);

  pivotCounterClockwise(90);

  moveForward(18);

  moveStackForward();

  intakeOut();

  moveForward(-5);

  MOTOR_INTAKE_A.stop();
  MOTOR_INTAKE_B.stop();

}

/**
  1. Move intake up so mechanisms  deploy
  2. Move intake back down
  3. Run intake and drive forward to pick up preload
  4. Score cubes
  */
void autonStart() {
  MOTOR_ARM.startRotateTo(3.5, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_A.startRotateFor(directionType::rev, 3, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(directionType::rev, 3, rotationUnits::rev, 100, velocityUnits::pct);

  moveForward(-6);

  vexDelay(2000);

  MOTOR_ARM.startRotateTo(.5, rotationUnits::rev, 100, velocityUnits::pct);
  //moveForward(5);
}
