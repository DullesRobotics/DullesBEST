#pragma config(Sensor, dgtl9,  sonarinput,     sensorSONAR_inch)
#pragma config(Motor,  port1,           light,         tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           FLM,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           FRM,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           BLM,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BRM,           tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//http://www.robotc.net/wikiarchive/VEX2_Functions_Remote_Control_-_VEXnet#vexRT

int FLMspeed, FRMspeed, BLMspeed,BRMspeed;
int rJoyX,rJoyY,lJoyX,lJoyY,xAccel,yAccel,zAccel,B8R,B8L,B8U,B8D,B5U,B5D,B6U,B6D;
int B8RprevVal,B8LprevVal = 0;
int DEFAULT_CONTROL_MODE = 1;
int controlMode = DEFAULT_CONTROL_MODE;
int prevMode = DEFAULT_CONTROL_MODE;
bool flashLightisOn = false;
/***
1 - arcade
2 - tank
3 - Acceleration
4 - Velocity Mode
5 - Autonomous Mode
***/
int NUM_TOTAL_OP_MODES = 5; // I tried #define but it didnt work for some reason
float prevTime;
float dx;
int velx,vely = 0;

void readController()//method dec has to be before calling it or it wont work - at least when I tried it
{
	rJoyX = vexRT[Ch1];//R joystick X (all online resources say Right X is ch1 but it doesnt work for us)
	rJoyY = vexRT[Ch2];//R joystick Y
	lJoyX = vexRT[Ch4];
	lJoyY = vexRT[Ch3];
	xAccel = vexRT[AccelX];
	yAccel = vexRT[AccelY];
	zAccel = vexRT[AccelZ];
	B8R = vexRT[Btn8R];
	B8L = vexRT[Btn8L];
	B8U = vexRT[Btn8U];
	B8D = vexRT[Btn8D];
	B5U = vexRT[Btn5U];
	B5D = vexRT[Btn5D];
	B6U = vexRT[Btn6U];
	B6D = vexRT[Btn6D];
}
task flashControlMode()//run in parallel w/ rest of code
{
	for(int i=1; i<controlMode;i++){
		turnFlashlightOn(light, -127);
		delay(200);
		turnFlashlightOff(light);
		delay(300);
	}
}
void checkBtnAndChangeMode()
{

	if(B8R > B8RprevVal) //If B8R pressed controlMode++
	{
		prevMode = controlMode;
		controlMode = ((controlMode+1)% NUM_TOTAL_OP_MODES)+1;//Add one to mode, wrap around
		startTask(flashControlMode);

	};
	if(B8L > B8LprevVal)//If B8L pressed controlMode--
	{
		prevMode = controlMode;
		controlMode = ((controlMode-1)% NUM_TOTAL_OP_MODES)+1;//Add one to mode, wrap around
		startTask(flashControlMode);
	}
	B8RprevVal = B8R;//This might fix the flashlight only blinking once
}

task main()
{

	while(true)
	{
		readController();
		checkBtnAndChangeMode();

		if(controlMode == 1)//Arcade Mode
		{

			FLMspeed = (rJoyY + rJoyX);
			BLMspeed = (rJoyY + rJoyX);

			FRMspeed = (rJoyY - rJoyX);
			BRMspeed = (rJoyY - rJoyX);

			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			motor[BLM] = BLMspeed;
			motor[BRM] = BRMspeed;

		}
		else if(controlMode == 2)//Tank Mode
		{
			FLMspeed = lJoyY;
			BLMspeed = lJoyY;
			FRMspeed = rJoyY;
			BRMspeed = rJoyY;
			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			motor[BLM] = BLMspeed;
			motor[BRM] = BRMspeed;
		}
		else if(controlMode == 3)//Accel Mode
		{

			FLMspeed = (yAccel + xAccel);
			BLMspeed = (yAccel + xAccel);

			FRMspeed = (yAccel - xAccel);
			BRMspeed = (yAccel - xAccel);

			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			motor[BLM] = BLMspeed;
			motor[BRM] = BRMspeed;
		}
		else if(controlMode == 4)//Velocity Mode (Integrate Accel mode)
		{
			if(prevMode!=4)
			{
				clearTimer(T1);//Clear and start timer T1
				prevTime = time1[T1];
			}
			dx = time1[T1] - prevTime;
			prevTime = time1[T1];
			velx += (int)((((dx)*AccelX))/1000);
			vely += (int)((((dx)*AccelY))/1000);

			FLMspeed = (vely + velx);
			BLMspeed = (vely + velx);

			FRMspeed = (vely - velx);
			BRMspeed = (vely - velx);

			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			motor[BLM] = BLMspeed;
			motor[BRM] = BRMspeed;
		}
		else if(controlMode == 5)
		{
			if(SensorValue[sonarinput] > 10){
				if(flashLightisOn)
				{
					turnFlashlightOff(light);
					flashLightisOn = false;
				}
				motor[FLM] = 100;
				motor[FRM] = 100;
				motor[BLM] = 100;
				motor[BRM] = 100;
			}
			else{
				if(!flashLightisOn)
				{
					turnFlashlightOn(light, -127);
					flashLightisOn = true;
				}
				motor[FLM] = -100;
				motor[FRM] = -100;
				motor[BLM] = -100;
				motor[BRM] = -100;
			}

		}

	}//end While
}
