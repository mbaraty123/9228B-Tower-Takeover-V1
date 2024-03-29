#ifndef DRIVE_H
#define DRIVE_H

#include "controller.h"

enum class DriveSide : int {
    LEFT = 0,
    RIGHT = 1,
    BOTH = 2
 };

void arcadeDrive();

void tankDrive();

void setSideSpeed(DriveSide side, int speed);

void drive();

void moveStackForward();

void moveStackBack();

void stackControl();

#endif