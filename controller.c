/*	Controller test   */
//You may have to reverse some motors |
//																		|
//																		V

#pragma config(Sensor, port9,  bumpSwitch,     sensorNone)
#pragma config(Motor,  motor2,          FLM,           tmotorVexIQ, openLoop, driveLeft)
#pragma config(Motor,  motor3,          FRM,           tmotorVexIQ, PIDControl, driveRight, encoder)
#pragma config(Motor,  motor4,          BLM,           tmotorVexIQ, openLoop, driveLeft)
#pragma config(Motor,  motor5,          BRM,           tmotorVexIQ, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int FLMspeed, FRMspeed, BLMspeed,BRMspeed;
int xDrive,yDrive;

void readController(){ //method dec has to be before calling it or it wont work - at least when I tried it
		xDrive = vexRT[Ch1];
		yDrive = vexRT[Ch2];
}

task main()
{
	while(true){

		//Store controller input values since idk how fast the values update & may cause problems if they change in the middle of a loop
		//probably not needed now but might be useful later when doing more processing
		readController();

		FLMspeed = yDrive - xDrive; // minus because right direction is +
		BLMspeed = yDrive - xDrive; // minus because right direction is +

		FRMspeed = yDrive + xDrive;
		BRMspeed = yDrive + xDrive;

		motor[FLM] = FLMspeed;
		motor[FRM] = FRMspeed;
		motor[BLM] = BLMspeed;
		motor[BRM] = BRMspeed;


	}
}