/**
  * Declares the autonomous functions for the robot
  * @author Michael Baraty
  * @date 11/9/2019
  */
#ifndef AUTON_H
#define AUTON_H

/**
  * Moves the robot forward for a certain distance
  * @param inches The distance to move in inches (negative for reverse)
  * @author Michael Baraty
  * @date 11/9/2019
  */
bool moveForward(double inches, double speed, bool blocking);

/**
  * Pivots the robot clockwise to a certain angle
  * @param degrees The number of degrees to pivot the robot
  * @author Michael Baraty
  * @date 11/9/2019
  */
bool pivotClockwise(float degrees);

/**
  * Pivots the robot counter-clockwise to a certain angle
  * @param degrees The number of degrees to pivot the robot
  * @author Michael Baraty
  * @date 11/9/2019
  */
bool pivotCounterClockwise(float degrees);

/**
  * Declares the possible autonomous colors for the autonomous switcher
  * @author Michael Baraty
  * @date 11/9/2019
  */
enum class Color : bool {
  BLUE = false,
  RED = true
};

/**
  * Declares the possible autonomous starting side for the autonomous switcher
  * @author Michael Baraty
  * @date 11/9/2019
  */
enum class Side : bool {
  LEFT = false,
  RIGHT = true
};

/**
  * Initiates the specified autonomous routine
  * @param side The side in relastion to the zone th erobot is going ot be near
  * @param color The color the robot is starting in
  * @author Michael Baraty
  * @date 11/9/2019
  */
void auton(Side side, Color color);

/**
  * Initiates the autonomous routine to release the mechanisms
  * @author Michael Baraty
  * @date 11/9/2019
  */
bool autonStart();

/**
  * Initiates blue left autonomous routine
  * @author Michael Baraty
  * @date 11/9/2019
  */
void autonBlueLeft();

/**
  * Initiates blue right autonomous routine
  * @author Michael Baraty
  * @date 11/9/2019
  */
void autonBlueRight();

/**
  * Initiates red left autonomous routine
  * @author Michael Baraty
  * @date 11/9/2019
  */
void autonRedLeft();

/**
  * Initiates red right autonomous routine
  * @author Michael Baraty
  * @date 11/9/2019
  */
void autonRedRight();

void badAuton(Side side, Color color);

void badAutonBlueLeft();

void badAutonBlueRight();

void badAutonRedLeft();

void badAutonRedRight();

#endif