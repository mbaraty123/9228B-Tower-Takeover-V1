/**
  * Declares all the contants necessary for the entire project
  * @file declarations.h
  * @author Michael Baraty
  * @date 11/9/2019
  */
#ifndef DECLARATIONS_H
#define DECLARATIONS_H

using namespace vex;

/**
  * Makes the main controller accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern controller MASTER;

/**
  * Makes the back left motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_BACK_LEFT;

/**
  * Makes the back right motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_BACK_RIGHT;

/**
  * Makes the front left motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern  motor MOTOR_FRONT_LEFT;

/**
  * Makes the front right motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_FRONT_RIGHT;

/**
  * Makes the right intake motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_INTAKE_A;

/**
  * Makes the left intake motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_INTAKE_B;

/**
  * Makes the stack mechanism motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_STACK;

/**
  * Makes the intake lifter motor accessible in other files than main.cpp
  * @author Michael Baraty
  * @date 11/9/2019
  */
extern motor MOTOR_ARM;

/**
  * Declares the minimum motor power to move that cancels out friction
  * @author Michael Baraty
  * @date 11/9/2019
  */
static int THRESHOLD = 5;

/**
  * Declares the speed multiplier for the drivebase of the robot
  * @author Michael Baraty
  * @date 11/9/2019
  */
static float SPEED_MULTIPLIER = .9;

/**
  * Declares the diameter of each wheel to facilitate autonomous programming
  * @author Michael Baraty
  * @date 11/9/2019
  */
static float WHEEL_DIAMETER = 4;

/**
  * Declares the inches the robot will move per single rotation of the wheel to facilitate autonomous
  * @author Michael Baraty
  * @date 11/9/2019
  */
static double INCHES_PER_ROTATION = 12.56;

/**
  * Declares the number of rotations that it will take to move the robot an inch
  * @author Michael Baraty
  * @date 11/9/2019
  */
static float ROTATIONS_PER_INCH = .07962;


#endif