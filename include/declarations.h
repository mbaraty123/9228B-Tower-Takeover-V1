#ifndef DECLARATIONS_H
#define DECLARATIONS_H
using namespace vex;

extern controller MASTER;

extern motor MOTOR_BACK_LEFT;
extern motor MOTOR_BACK_RIGHT;
extern  motor MOTOR_FRONT_LEFT;
extern motor MOTOR_FRONT_RIGHT;
extern motor MOTOR_INTAKE_A;
extern motor MOTOR_INTAKE_B;
extern motor MOTOR_STACK;
extern motor MOTOR_ARM;

static int THRESHOLD = 5;
static float SPEED_MULTIPLIER = .9;
static float WHEEL_DIAMETER = 4;
static double INCHES_PER_ROTATION = .07962;
static float ROTATIONS_PER_INCH = 12.56;
static float INCHES_PER_MSEC = .021;
static double REVOLUTIONS_PER_MSEC = .0016666667;
static double MSEC_PER_INCH = (476.19 * 2);


#endif