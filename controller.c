#pragma config(Sensor, dgtl1,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl7,  buttonPress,    sensorTouch)
#pragma config(Motor,  port2,           frontMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           crane,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          backMotor,     tmotorVex393_HBridge, openLoop, reversed)

task main()
{
	while(true){
		motor[frontMotor] = vexRT[Ch2];
		motor[backMotor] = vexRT[Ch2];
		motor[crane] = vexRT[Ch3];

	}
}
