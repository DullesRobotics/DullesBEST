#pragma config(Sensor, dgtl9,  sonarInput,     sensorSONAR_cm)
#pragma config(Motor,  port3,           wheelOne,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port4,           armMotor,      tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true){
		if(SensorValue[sonarInput] < 10){
			motor[wheelOne] = 100;
		}
		else{
			motor[wheelOne] = -100;
		}
	}
}
