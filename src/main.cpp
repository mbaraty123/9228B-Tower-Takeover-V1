/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       mbaraty                                                   */
/*    Created:      Thu Sep 12 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "drive.h"
#include "auton.h"

using namespace vex;

// A global instance of vex::competition
vex::competition Competition;
vex::brain Brain;
controller MASTER = controller();

task printTask;

motor MOTOR_BACK_LEFT   = motor(PORT9, false);
motor MOTOR_BACK_RIGHT  = motor(PORT3, true);
motor MOTOR_FRONT_LEFT  = motor(PORT10, false);
motor MOTOR_FRONT_RIGHT = motor(PORT2, true);
motor MOTOR_INTAKE_A    = motor(PORT15, gearSetting::ratio36_1, true);
motor MOTOR_INTAKE_B    = motor(PORT16, gearSetting::ratio36_1, false);
motor MOTOR_STACK       = motor(PORT17, false);
motor MOTOR_ARM         = motor(PORT12, gearSetting::ratio36_1, true);

// define your global instances of motors and other devices here

int printDisplay() {
  while(true){
    printf("%2.2f\n BACK LEFT:   ", MOTOR_BACK_LEFT.temperature(temperatureUnits::celsius));
    printf("%2.2f\n BACK RIGHT:  ", MOTOR_BACK_RIGHT.temperature(temperatureUnits::celsius));
    printf("%2.2f\n FRONT LEFT:  ", MOTOR_FRONT_LEFT.temperature(temperatureUnits::celsius));
    printf("%2.2f\n FRONT RIGHT: ", MOTOR_FRONT_RIGHT.temperature(temperatureUnits::celsius));
    printf("%2.2f\n INTAKE A:    ", MOTOR_INTAKE_A.temperature(temperatureUnits::celsius));
    printf("%2.2f\n INTAKE B:    ", MOTOR_INTAKE_B.temperature(temperatureUnits::celsius));
    printf("%2.2f\n ARM:         ", MOTOR_ARM.temperature(temperatureUnits::celsius));
    printf("%2.2f\n MAGAZINE:    ", MOTOR_STACK.temperature(temperatureUnits::celsius));

    
    task::sleep(1000);
  }
}


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {

  //printDisplay();

  auton(Side::LEFT, Color::RED);

  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop

  //printDisplay();

  while (1) {
    drive();

    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();

    
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      printTask = task(printDisplay);
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}