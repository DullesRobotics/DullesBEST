#pragma config(Sensor, dgtl9,  sonarinput,     sensorSONAR_inch)
#pragma config(Motor,  port2,           FLM,           tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           FRM,           tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port4,           BLM,           tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           BRM,           tmotorVex393_MC29, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Sensor, port9,  bumpSwitch,     sensorNone)
//http://www.robotc.net/wikiarchive/VEX2_Functions_Remote_Control_-_VEXnet#vexRT
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int FLMspeed, FRMspeed, BLMspeed,BRMspeed;
int xDrive,yDrive,xAccel,yAccel;
bool enableExperimental = true;
void readController(){ //method dec has to be before calling it or it wont work - at least when I tried it
	xDrive = -vexRT[Ch2];
	yDrive = vexRT[Ch1];
}

task main()
{
	if(!enableExperimental){
		while(true){

			//Store controller input values since idk how fast the values update & may cause problems if they change in the middle of a loop
			//probably not needed now but might be useful later when doing more processing

			readController();

			FLMspeed = (yDrive - xDrive); // minus because right direction is +
			BLMspeed = (yDrive - xDrive); // minus because right direction is +

			FRMspeed = (yDrive + xDrive);
			BRMspeed = (yDrive + xDrive);

			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			motor[BLM] = BLMspeed;
			motor[BRM] = BRMspeed;
			}
			} else if(enableExperimental){
			readController();

			FLMspeed = (yAccel - xAccel); // minus because right direction is +
			BLMspeed = (yAccel - xAccel); // minus because right direction is +

			FRMspeed = (yAccel + xAccel);
			BRMspeed = (yAccel + xAccel);

			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			motor[BLM] = BLMspeed;
			motor[BRM] = BRMspeed;
			}


		}
		while(true)
<<<<<<< HEAD
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
=======
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

	}
}
>>>>>>> origin/master
}
