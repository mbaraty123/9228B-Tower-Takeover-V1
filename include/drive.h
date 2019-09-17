#ifndef DRIVE_H
#define DRIVE_H

#include "controller.h"


enum class DriveSide : int {
    LEFT = 0,
    RIGHT = 1,
    BOTH = 2
 };

void arcadeDrive();

void setMotorSpeed(DriveSide side, int speed);


#endif