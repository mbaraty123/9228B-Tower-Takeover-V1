#ifndef DECLARATIONS_H
#define DECLARATIONS_H
using namespace vex;

brain Brain;

controller MASTER = controller();

motor MOTOR_BACK_LEFT   = motor(1, false);
motor MOTOR_BACK_RIGHT  = motor(2, false);
motor MOTOR_FRONT_LEFT  = motor(3, false);
motor MOTOR_FRONT_RIGHT = motor(4, false);
motor MOTOR_LIFT_A      = motor(5, false);
motor MOTOR_LIFT_B      = motor(6, false);
motor MOTOR_ARM         = motor(7, false);
motor MOTOR_CLAW        = motor(8, false);

static int THRESHOLD = 5;

#endif