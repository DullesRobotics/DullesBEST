#pragma config(Sensor, dgtl9,  sonarinput,     sensorSONAR_cm)
#pragma config(Motor,  port2,           FLM,           tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           FRM,           tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           BLM,           tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           BRM,           tmotorVex393_MC29, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true)
	{
		if(SensorValue[sonarinput] > 10){
			motor[FLM] = 100;
			motor[FRM] = 100;
			motor[BLM] = 100;
			motor[BRM] = 100;
		}
		else{
			motor[FLM] = -100;
			motor[FRM] = -100;
			motor[BLM] = -100;
			motor[BRM] = -100;
		}
	}
}
