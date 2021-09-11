#pragma once
#include "main.h"

namespace drive
{
	/*int joyLX;
	int joyLY;
	int joyRX;
	int joyRY;
	int strifeVal;*/
	void control();
	void control(int input);
	void setBrakeMode(okapi::Motor::brakeMode b);
	void setDriveVelocity(int v1, int v2, int v3, int v4);	
}
