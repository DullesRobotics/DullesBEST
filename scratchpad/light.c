#pragma config(Motor,  port1,           light,         tmotorVexFlashlight, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int x = 0;
	while(true){
		x = vexRT[Ch2];

		if(x <0){
			x = 0;
		}
		turnFlashlightOn(light,-x);
		delay(1);
		turnFlashlightOff(light);
		delay(1);
	}


}
