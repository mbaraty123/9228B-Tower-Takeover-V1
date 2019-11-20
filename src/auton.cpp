#include "auton.h"
#include "drive.h"
#include "declarations.h"

bool moveForward(double inches, double speed = 50, bool blocking = true) {


  double rotations = inches * ROTATIONS_PER_INCH;
  if(blocking) {
    MOTOR_BACK_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
    MOTOR_BACK_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
    MOTOR_FRONT_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
    MOTOR_FRONT_RIGHT.rotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
  } else {
    MOTOR_BACK_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
    MOTOR_BACK_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
    MOTOR_FRONT_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
    MOTOR_FRONT_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev, speed, velocityUnits::pct);
  }
  return true;
}

bool pivotClockwise(float degrees) {
  double rotations_per_360 = 6.5;
  double rotations = rotations_per_360 * (degrees / 360);

  MOTOR_BACK_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_BACK_RIGHT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
  MOTOR_FRONT_LEFT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_RIGHT.rotateFor(directionType::rev, rotations, rotationUnits::rev);

  return true;
}

bool pivotCounterClockwise(float degrees) {
  double rotations_per_360 = 6.5;
  double rotations = rotations_per_360 * (degrees / 360);

  MOTOR_BACK_LEFT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
  MOTOR_BACK_RIGHT.startRotateFor(directionType::fwd, rotations, rotationUnits::rev);
  MOTOR_FRONT_LEFT.startRotateFor(directionType::rev, rotations, rotationUnits::rev);
  MOTOR_FRONT_RIGHT.rotateFor(directionType::fwd, rotations, rotationUnits::rev);

  return true;
}

/**
  * @brief the autonomous switcher
  * @author Michael Baraty
  */
void auton(Side side, Color color) {
  //autonStart();

  if(color == Color::BLUE && side == Side::LEFT)
    autonBlueLeft();
  else if (color == Color::BLUE && side == Side::RIGHT)
    autonBlueRight();
  else if (color == Color::RED && side == Side::LEFT)
    autonRedLeft();
  else if (color == Color::RED && side == Side::RIGHT)
    autonRedRight();
}


void autonBlueLeft(){
  autonStart();

  MOTOR_INTAKE_A.startRotateFor(20, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(20, rotationUnits::rev, 100, velocityUnits::pct);

  
  moveForward(35, 33);

  /*pivotClockwise(190);

  moveForward(24);

  pivotCounterClockwise(45);*/

  moveForward(-24, 60);

  pivotCounterClockwise(145);

  moveForward(12);

  MOTOR_INTAKE_A.rotateFor(-1.5, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.rotateFor(-1.5, rotationUnits::rev, 100, velocityUnits::pct);

  MOTOR_STACK.rotateTo(4, rev);

  MOTOR_INTAKE_A.startRotateFor(-20, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-20, rotationUnits::rev, 100, velocityUnits::pct);

  moveForward(-20);

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

  autonStart();

  MOTOR_INTAKE_A.startRotateFor(10, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(10, rotationUnits::rev, 100, velocityUnits::pct);

  
  moveForward(35, 33);

  /*pivotClockwise(190);

  moveForward(24);

  pivotCounterClockwise(45);*/

  moveForward(-24, 60);

  pivotClockwise(135);

  moveForward(10);

  moveForward(5, 30, false);

  MOTOR_INTAKE_A.startRotateFor(-1, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-1, rotationUnits::rev, 100, velocityUnits::pct);

  MOTOR_STACK.rotateFor(2, rev);

  MOTOR_INTAKE_A.startRotateFor(-20, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-20, rotationUnits::rev, 100, velocityUnits::pct);

  moveForward(-20, 33);

  MOTOR_INTAKE_A.stop();
  MOTOR_INTAKE_B.stop();

}

/**
  1. Move intake up so mechanisms  deploy
  2. Move intake back down
  3. Run intake and drive forward to pick up preload
  4. Score cubes
  */
bool autonStart() {

  MOTOR_INTAKE_A.startRotateFor(directionType::rev, 3, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(directionType::rev, 3, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_ARM.rotateTo(2, rotationUnits::rev, 100, velocityUnits::pct);

  MOTOR_STACK.startRotateTo(1.5, rev);

  MOTOR_ARM.rotateTo(3.4, rotationUnits::rev, 100, velocityUnits::pct);


  moveForward(3);

  MOTOR_STACK.startRotateTo(0, rev);

  MOTOR_ARM.rotateTo(-.15, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_ARM.stop(hold);

  moveForward(-15, 80);

  return true;
}
