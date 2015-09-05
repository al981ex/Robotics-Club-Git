#pragma config(Motor,  port1,           armMotor,      tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port6,           rightMotor,    tmotorVex269_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           clawMotor,     tmotorVex269_MC29, openLoop)

/*----------------------------------------------------------------------------------------------------*\
|*                           - Dual Joystick Control with Arm, Scoop and - 1 Remote -                            *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses both the Left and the Right joysticks to run the robot using "tank control".    *|
|*  The Group 6 buttons on the top-right of the VEXnet Joystick are used to raise and lower an arm.   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch1 is the X axis and Ch2 is the Y axis for the RIGHT joystick.                             *|
|*    2)  Ch3 is the Y axis and Ch4 is the X axis for the LEFT joystick.                              *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 2          rightMotor           VEX Motor           Right motor                    *|
|*    Motor - Port 6          leftMotor            VEX Motor           Left motor                     *|
|*    Motor - Port 7          armMotor             VEX Motor           Arm motor 											*|
|*		Motor - Port 8					clawMotor						 VEX Motor					 Scooper Motor									*|
\*----------------------------------------------------------------------------------------------------*/

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++

task main()
{
	while(1 == 1)
	{
		//Driving Motor Control
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];

		//Arm Control
		if(vexRT[Btn6U] == 1)
		{
			motor[armMotor] = -60;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[armMotor] = 20;
		}
		else
		{
			motor[armMotor] = 0;
		}

		//Claw Control
		if(vexRT[Btn5U] == 1)
		{
			motor[clawMotor] = -40;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[clawMotor] = 40;
		}
		else
		{
			motor[clawMotor] = 0;
		}

	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
