#ifndef DECLARATIONS_H
#define DECLARATIONS_H
using namespace vex;

controller MASTER = controller();

motor MOTOR_BACK_LEFT   = motor(PORT9, false);
motor MOTOR_BACK_RIGHT  = motor(PORT3, false);
motor MOTOR_FRONT_LEFT  = motor(PORT10, false);
motor MOTOR_FRONT_RIGHT = motor(PORT2, false);
motor MOTOR_INTAKE_A    = motor(PORT5, false);
motor MOTOR_INTAKE_B    = motor(PORT6, false);
motor MOTOR_STACK       = motor(PORT16, false);
motor MOTOR_ARM         = motor(PORT12, gearSetting::ratio36_1, true);

static int THRESHOLD = 5;
static float SPEED_MULTIPLIER = .9;
static float WHEEL_DIAMETER = 4;
static double INCHES_PER_ROTATION = .07962;
static float ROTATIONS_PER_INCH = 12.56;
#endif