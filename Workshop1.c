#pragma config(Motor,  port1,           FrontLeft,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           BackLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FrontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BackRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Center,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Workshop 1 - Introduction to DriveTrains
//PurpleFire 2017
//Author: Zach Weingarten

// This code is for the VEX cortex platform
#pragma platform(VEX2)
// Select Download method as "competition"
#pragma competitionControl(Competition)
//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

// Controller 1/2, Stick L/R, Axis X/Y
#define C1RY						                vexRT[Ch2]
#define C1LY						                vexRT[Ch3]
#define C1RX							              vexRT[Ch1]
#define C1LX								            vexRT[Ch4]

/*-------------------------------------------------------------*/
void pre_auton()
{
}

task autonomous()
{
	AutonomousCodePlaceholderForTesting();
}

/*-------------------------------------------------------------*/

//Tank Drive using 2 Inputs
void tankDrive(){
	//Send Left Axis to Left Motors
	motor[FrontLeft] = C1LY;
	motor[BackLeft] = C1LY;
	//Send Right Axis to Right Motors
	motor[FrontRight] = C1RY;
	motor[BackRight] = C1RY;
}

//H-Drive using 4 Inputs
void hDrive(){
	//Send Left Axis to Left Motors
	motor[FrontLeft] = C1LY;
	motor[BackLeft] = C1LY;
	//Send Right Axis to Right Motors
	motor[FrontRight] = C1RY;
	motor[BackRight] = C1RY;
	//Center Wheel Control
	motor[Center] = (vexRT[Btn5U] - vexRT[Btn6U])*127;
}

/*-------------------------------------------------------------*/
//DriveTrain Select Variable
//1. Tank Drive (Defualt)
//2. Holonomic Drive
//3. H-Drive
int driveSelect = 1;

// User control code, inside while loop
task usercontrol()
{
	while (true)
	{

		switch(driveSelect) {
		case 1: tankDrive();
			break;
		case 2: hDrive();
			break;
		default: tankDrive();
			break;
		}
		// Motor values can only be updated every 20ms
		wait1Msec(20);
	}
}
