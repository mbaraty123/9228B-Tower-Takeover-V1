#include "controller.h"


int axisValue(controller::axis Axis) {
  return Axis.position();
}

bool buttonIsPressed(controller::button Button) {
  return Button.pressing();
}




 