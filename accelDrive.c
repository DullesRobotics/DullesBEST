#pragma config(Sensor, dgtl9,  sonarinput,     sensorSONAR_inch)
#pragma config(Motor,  port1,           light,         tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           FLM,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FRM,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           BLM,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BRM,           tmotorVex393_MC29, openLoop, reversed)
#include "library.h";

task main()
{
	while(true){
		readController();
		FLMspeed = (yAccel + xAccel);
		BLMspeed = (yAccel + xAccel);
		FRMspeed = (yAccel - xAccel);
		BRMspeed = (yAccel - xAccel);
		setMotorsToRespectiveSpeeds();
	}


}
