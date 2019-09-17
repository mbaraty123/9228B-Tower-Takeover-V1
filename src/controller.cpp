#include "controller.h"


int axisValue(controller::axis Axis) {
  return Axis.value();
}

bool buttonIsPressed(controller::button Button) {
  return Button.pressing();
}




 