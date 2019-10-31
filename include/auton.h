#ifndef AUTON_H
#define AUTON_H

void moveForward(double inches);

void pivotClockwise(float degrees);

void pivotCounterClockwise(float degrees);

enum class Color : bool {
  BLUE = false,
  RED = true
};

enum class Side : bool {
  LEFT = false,
  RIGHT = true
};

void auton(Side side, Color color);

void autonStart();

void autonBlueLeft();
void autonBlueRight();
void autonRedLeft();
void autonRedRight();

#endif