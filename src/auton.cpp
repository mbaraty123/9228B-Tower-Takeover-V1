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

bool pivotClockwise(float degrees, bool blocking = true) {
  double rotations_per_360 = 6.4;
  double rotations = rotations_per_360 * (degrees / 360);

  if(blocking){
  MOTOR_BACK_LEFT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_BACK_RIGHT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_FRONT_LEFT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_FRONT_RIGHT.rotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  } else {
    MOTOR_BACK_LEFT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
    MOTOR_BACK_RIGHT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
    MOTOR_FRONT_LEFT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
    MOTOR_FRONT_RIGHT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  }

  return true;
}

bool pivotCounterClockwise(float degrees, bool blocking = true) {
  double rotations_per_360 = 6.4;
  double rotations = rotations_per_360 * (degrees / 360);

  if(blocking) {
  MOTOR_BACK_LEFT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_BACK_RIGHT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_FRONT_LEFT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_FRONT_RIGHT.rotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
  } else {
    MOTOR_BACK_LEFT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_BACK_RIGHT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_FRONT_LEFT.startRotateFor(-rotations, rotationUnits::rev, 80, velocityUnits::pct);
  MOTOR_FRONT_RIGHT.startRotateFor(rotations, rotationUnits::rev, 80, velocityUnits::pct);
  }
  return true;
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
    autonBlueRight();
  else if (color == Color::RED && side == Side::LEFT)
    autonRedLeft();
  else if (color == Color::RED && side == Side::RIGHT)
    autonRedRight();
}


void autonBlueLeft(){
  MOTOR_INTAKE_A.startRotateFor(7, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(7, rotationUnits::rev, 100, velocityUnits::pct);
  moveForward(35, 33);
  /*pivotClockwise(190);
  moveForward(24);
  pivotCounterClockwise(45);*/
  moveForward(-24, 60);
  pivotCounterClockwise(135);
  moveForward(10);
  moveForward(5, 30, false);
  MOTOR_INTAKE_A.startRotateFor(-.5, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-.5, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_STACK.rotateFor(2, rev);
  MOTOR_INTAKE_A.startRotateFor(-20, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-20, rotationUnits::rev, 100, velocityUnits::pct);
  moveForward(-20, 33);
  MOTOR_INTAKE_A.stop();
  MOTOR_INTAKE_B.stop();
}

void autonBlueRight(){
  intakeIn();
  moveForward(25, 70);
  moveForward(12, 40);
  vexDelay(1000);
  MOTOR_INTAKE_A.stop(hold);
  MOTOR_INTAKE_B.stop(hold);
  moveForward(-28, 80);
  pivotClockwise(130);
  moveForward(29, 50);
  //MOTOR_INTAKE_A.rotateFor(-.25, rotationUnits::rev, 100, velocityUnits::pct);
  //MOTOR_INTAKE_B.rotateFor(-.25, rotationUnits::rev, 100, velocityUnits::pct);
  //MOTOR_STACK.startRotateTo(2.9, rotationUnits::rev);
  //vexDelay(1500);
  
  MOTOR_INTAKE_A.startRotateFor(-10, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-10, rotationUnits::rev, 100, velocityUnits::pct);
  pivotClockwise(60, true);

  moveForward(-13, 33, true);
  
  MOTOR_STACK.rotateTo(0, rotationUnits::rev, 80, velocityUnits::pct);
}

void autonRedLeft(){
  intakeIn();
  moveForward(25, 70);
  moveForward(12, 40);
  vexDelay(1000);
  MOTOR_INTAKE_A.stop(hold);
  MOTOR_INTAKE_B.stop(hold);
  moveForward(-28, 80);
  pivotCounterClockwise(130);
  moveForward(29, 50);
  //MOTOR_INTAKE_A.rotateFor(-.25, rotationUnits::rev, 100, velocityUnits::pct);
  //MOTOR_INTAKE_B.rotateFor(-.25, rotationUnits::rev, 100, velocityUnits::pct);
  //MOTOR_STACK.startRotateTo(2.9, rotationUnits::rev);
  //vexDelay(1500);
  
  MOTOR_INTAKE_A.startRotateFor(-10, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-10, rotationUnits::rev, 100, velocityUnits::pct);
  pivotCounterClockwise(60, true);
  
  moveForward(-13, 33, true);
  
  MOTOR_STACK.rotateTo(0, rotationUnits::rev, 80, velocityUnits::pct);
}

void autonRedRight(){
  MOTOR_INTAKE_A.startRotateFor(7, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(7, rotationUnits::rev, 100, velocityUnits::pct);
  moveForward(35, 33);
  /*pivotClockwise(190);
  moveForward(24);
  pivotCounterClockwise(45);*/
  moveForward(-24, 60);
  pivotClockwise(135);
  moveForward(10);
  moveForward(5, 30, false);
  MOTOR_INTAKE_A.startRotateFor(-.5, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_INTAKE_B.startRotateFor(-.5, rotationUnits::rev, 100, velocityUnits::pct);
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

  MOTOR_ARM.rotateTo(3.9, rotationUnits::rev, 100, velocityUnits::pct);


  moveForward(3);

  MOTOR_STACK.startRotateTo(0, rev);

  MOTOR_ARM.rotateTo(-.15, rotationUnits::rev, 100, velocityUnits::pct);
  MOTOR_ARM.stop(hold);

  moveForward(-15, 80);

  return true;
}


void badAuton(Side side, Color color) {

  if(color == Color::BLUE && side == Side::LEFT)
    badAutonBlueLeft();
  else if (color == Color::BLUE && side == Side::RIGHT)
    badAutonBlueRight();
  else if (color == Color::RED && side == Side::LEFT)
    badAutonRedLeft();
  else if (color == Color::RED && side == Side::RIGHT)
    badAutonRedRight();
}


void badAutonBlueLeft(){

}

void badAutonBlueRight(){

}

void badAutonRedLeft(){

}

void badAutonRedRight(){

}