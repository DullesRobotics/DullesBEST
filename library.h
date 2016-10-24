int FLMspeed, FRMspeed;
int rJoyX,rJoyY,lJoyX,lJoyY,xAccel,yAccel,zAccel,B8R,B8L,B8U,B8D,B5U,B5D,B6U,B6D = 0;
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
void setMotorsToRespectiveSpeeds()
{
			motor[FLM] = FLMspeed;
			motor[FRM] = FRMspeed;
			//motor[BLM] = BLMspeed;
			//motor[BRM] = BRMspeed;
}
void arcadeDriveLoopContent()
{
		readController();
		FLMspeed = (rJoyY + rJoyX);
		//BLMspeed = (rJoyY + rJoyX);
		FRMspeed = (rJoyY - rJoyX);
		//BRMspeed = (rJoyY - rJoyX);
		setMotorsToRespectiveSpeeds();
}
/*void tankDriveLoopContent()
{
		readController();
		FLMspeed = lJoyY;
		BLMspeed = lJoyY;
		FRMspeed = rJoyY;
		BRMspeed = rJoyY;
		setMotorsToRespectiveSpeeds();
}
void accelDriveLoopContent()
{
		readController();
		FLMspeed = (yAccel + xAccel);
		BLMspeed = (yAccel + xAccel);
		FRMspeed = (yAccel - xAccel);
		BRMspeed = (yAccel - xAccel);
		setMotorsToRespectiveSpeeds();
}*/
