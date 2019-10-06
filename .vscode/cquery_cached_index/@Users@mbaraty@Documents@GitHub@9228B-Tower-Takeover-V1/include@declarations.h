#ifndef DECLARATIONS_H
#define DECLARATIONS_H
using namespace vex;

brain Brain;

controller MASTER = controller();

motor MOTOR_BACK_LEFT   = motor(9, false);
motor MOTOR_BACK_RIGHT  = motor(3, false);
motor MOTOR_FRONT_LEFT  = motor(10, false);
motor MOTOR_FRONT_RIGHT = motor(2, false);
motor MOTOR_INTAKE_A    = motor(5, false);
motor MOTOR_INTAKE_B    = motor(6, false);
motor MOTOR_STACK       = motor(16, false);
motor MOTOR_CLAW        = motor(8, false);

static int THRESHOLD = 5;

#endif