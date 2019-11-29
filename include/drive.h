/**
  * Declares all the basic movement functions for the robot
  * @file drive.h
  * @author Michael Baraty
  * @date 11/9/2019
  */
#ifndef DRIVE_H
#define DRIVE_H

#include "controller.h"

/**
  * Declares the different possible motor combinations to drive the robot
  * @author Michael Baraty
  * @date 11/9/2019
  */
enum class DriveSide : int {
    LEFT = 0,
    RIGHT = 1,
    BOTH = 2
 };

/**
  * Initiates the arcade control configuration for the controller, with the left y axis for linear movement and the right x axis for pivoting
  * @author Michael Baraty
  * @date 11/9/2019
  */
void arcadeDrive();

/**
  * Initiates the tank drive control configuration for the controller, with the left y axis for the left side and the right y axis for the right side
  * @author Michael Baraty
  * @date 11/9/2019
  */
void tankDrive();

/**
  * Sets the speed of the designated drive side
  * @param side The DriveSide that is going to be powered
  * @param speed The speed that the robot will move at between -100 - 100
  * @author Michael Baraty
  * @date 11/9/2019
  */
void setSideSpeed(DriveSide side, int speed);

/**
  * Initiates the drive code for the entire robot
  * @author Michael Baraty
  * @date 11/9/2019
  */
void drive();

/**
  * Moves the stack forward to a specified position
  * @author Michael Baraty
  * @date 11/9/2019
  */
void moveStackForward();

/**
  * Moves the stack backwards to a specified position
  * @author Michael Baraty
  * @date 11/9/2019
  */
void moveStackBack();

/**
  * Reads the controller's button inputs to initiate the stack mechanism's movement while the button is being pressed
  * @author Michael Baraty
  * @date 11/9/2019
  */
void stackControl();

/**
  * Moves the intake lifter up to a specified position
  * @author Michael Baraty
  * @date 11/9/2019
  */
void armUp();

/**
  * Moves the intake lifter down to a specified position
  * @author Michael Baraty
  * @date 11/9/2019
  */
void armDown();

/**
  * Reads the controller's button inputs to initiate the arm lifter's movement while the button is being pressed
  * @author Michael Baraty
  * @date 11/9/2019
  */
void armControl();

/**
  * Spins the intake to intake the cubes
  * @author Michael Baraty
  * @date 11/9/2019
  */
void intakeIn();

/**
  * Spins the intake to eject the cubes
  * @author Michael Baraty
  * @date 11/9/2019
  */
void intakeOut();

/**
  * Reads the controller's button inputs to spin the intake while the button is being pressed
  * @author Michael Baraty
  * @date 11/9/2019
  */
void intakeControl();


#endif