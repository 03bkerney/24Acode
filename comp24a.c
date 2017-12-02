#pragma config(Motor,  port2,           PivotMotor,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           ChainBar,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LeftGoalLift,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RightGoalLift, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           RightDrive,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LeftDrive,     tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

#define RMR vexRT [Ch3]
#define RML vexRT [Ch2]
#define BGU vexRT [Btn5U]
#define BGD vexRT [Btn5D]
#define BCU vexRT [Btn6U]
#define BCD vexRT [Btn6D]
#define BCO vexRT [Btn8L]
#define BCC vexRT [Btn8R]

#define MLD motor[LeftDrive]
#define MRD motor[RightDrive]
#define MRG motor[RightGoalLift]
#define MLG motor[LeftGoalLift]
#define MCB motor[ChainBar]
#define MCW motor[Claw]
#define MPV motor[PivotMotor]

const int DRIVE_TH_LOW = 7;
const int DRIVE_TH_HIGH = 78;



void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}


task autonomous()
{

	//hold claw closed
	motor[Claw] = -90;
	wait1Msec(10000);
	//lift up arm
	motor[ChainBar] = 90;
	wait1Msec(200);
	motor[ChainBar] = 0;
	wait1Msec(500);
	// put down goal lift
	motor[LeftGoalLift] = motor[RightGoalLift] = -90;
	wait1Msec(1700);
	motor[LeftGoalLift] = motor[RightGoalLift] = 0;
	wait1Msec(500);
	//drive forward to the mobile goal
	motor[LeftDrive] = motor[RightDrive] = 75;
	wait1Msec(1700);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	//lift up goal lift to pick up mobile goal
	motor[LeftGoalLift] = motor[RightGoalLift] = 90;
	wait1Msec(1700);
	motor[LeftGoalLift] = motor[RightGoalLift] = 0;
	wait1Msec(500);
	// open claw to drop cone
	motor[Claw] = 90;
	wait1Msec(500);
	motor[Claw] = 0;
	wait1Msec(500);
	// backup to clear mobile goal
	motor[LeftDrive] = motor[RightDrive] = -90;
	wait1Msec(450);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	//turn to the right
	motor[LeftDrive] = -90;
	motor[RightDrive] = 90;
	wait1Msec(575);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	// drive forward
	motor[LeftDrive] = motor[RightDrive] = 90;
	wait1Msec(450);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	//turn to the left 90
	motor[LeftDrive] = -90;
	motor[RightDrive] = 90;
	wait1Msec(180);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	//drive forward
	motor[LeftDrive] = motor[RightDrive] = 90;
	wait1Msec(1450);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	// put arm down
	motor[LeftGoalLift] = motor[RightGoalLift] = -90;
	wait1Msec(1700);
	motor[LeftGoalLift] = motor[RightGoalLift] = 0;
	wait1Msec(500);
	//backup
	motor[LeftDrive] = motor[RightDrive] = -90;
	wait1Msec(1000);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
	//lift up arm
	motor[LeftGoalLift] = motor[RightGoalLift] = 90;
	wait1Msec(1000);
	motor[LeftGoalLift] = motor[RightGoalLift] = 0;
	wait1Msec(500);
	//backup
	motor[LeftDrive] = motor[RightDrive] = -90;
	wait1Msec(500);
	motor[LeftDrive] = motor[RightDrive] = 0;
	wait1Msec(500);
}


task controlDrive()
{
	while (true)
	{
		if (abs(RML) > DRIVE_TH_HIGH)
		{
			MLD = RML * 2;
		}
		else if (abs(RML) > DRIVE_TH_LOW)
		{
			MLD = RML;
		}
		else {
			MLD = 0;
		}

		if (abs(RMR) > DRIVE_TH_HIGH)
		{
			MRD = RMR * 2;
		}
		else if (abs(RMR) > DRIVE_TH_LOW)
		{
			MRD = RMR;
		}
		else {
			MRD = 0;
		}
	}
}

bool btnIsPushed = false;

task usercontrol()
{
	startTask(controlDrive);

	while (true)
	{
		//todo:
		//toggle boolean to run lift

		//pivot code
		if (vexRT[Btn8L] == 1)
		{
			btnIsPushed = true;
			MPV = 90;
		}
		else if (vexRT[Btn8R] == 1)
		{
			btnIsPushed = true;
			MPV = -90;
		}
		else
		{
			btnIsPushed = false;
			MPV = 0;
		}



		//write code to run lift
		if (vexRT[Btn6U] == 1)
		{
			btnIsPushed = true;
			MCB = 90;
		}
		else if (vexRT[Btn6D] == 1)
		{
			btnIsPushed = true;
			MCB = -90;
			} else {
			btnIsPushed = false;
			MCB = 0;
		}



		//write code for claw
		if (vexRT[Btn8U] == 1)
		{
			btnIsPushed = true;
			MCW = 90;
		}
		else if (vexRT[Btn8L] == 1)
		{
			btnIsPushed = true;
			MCW = -90;
		}
		else
		{
			btnIsPushed = false;
			MCW = 0;
		}



		// mobile goal lift code
		if (vexRT[Btn5U] == 1)
		{
			btnIsPushed = true;
			MRG = MLG = 127;
		}
		else if (vexRT[Btn5D] == 1)
		{
			btnIsPushed = true;
			MRG = MLG = -127;
		}
		else
		{
			btnIsPushed = false;
			MRG = MLG = 0;
		}

	}

}
