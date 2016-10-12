#pragma config(Sensor, dgtl1,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl7,  buttonPress,    sensorTouch)
#pragma config(Motor,  port2,           frontMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           crane,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          backMotor,     tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true){
		if(SensorValue(bumpSwitch) == 1) {
			motor[frontMotor] = 127;
		}
		else {
			motor[frontMotor] = 0;
		}
	if(SensorValue(buttonPress) == 1) {
			motor[crane] = 127;
		}
	  else {
	  	motor[crane] = -127;
	  }
	 if(SensorValue(bumpSwitch) == 1) {
	   motor[backMotor] = 127;
	 }
	 else if (SensorValue(bumpSwitch) == 0){
	   motor[backMotor] = 0;
	 }
}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
