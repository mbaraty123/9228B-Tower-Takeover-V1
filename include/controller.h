/**
  * Declares the functions to simplify reading commands on the controller
  * @file controller.h
  * @author Michael Baraty
  * @date 11/9/2019
  */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vex.h"

using namespace vex;

/**
  * Returns an axis value of the controller in a -100 - 100 scale, designed to be used with motor speeds in percent
  * @param Axis the axis on the controller that will be read (Ex. [controller].axis3 for the left x axis)
  * @author Michael Baraty
  * @date 11/9/2019
  */
int axisValue (controller::axis Axis);

/**
  * Returns a boolean for whether a designated button is being pressed
  * @param Button the button on the controller that will be read (Ex. [controller].buttonA for the A button)
  * @author Michael Baraty
  * @date 11/9/2019
  */
bool buttonIsPressed (controller::button Button);

#endif