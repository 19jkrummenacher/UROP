#include "drive.hpp"
#include "main.h"

namespace drive
{
	//global variables.
	int joyLX;
	int joyLY;
	int joyRX;
	int joyRY;
	int strifeVal;
	
	
	void control()
	{
		//take in the controllers joy values and scale them to the velocity of the cartrigde.
		joyLX = sensors::controllerMaster.getAnalog(okapi::ControllerAnalog::leftX) * 600;
		joyLY = sensors::controllerMaster.getAnalog(okapi::ControllerAnalog::leftY) * 600;
		joyRX = sensors::controllerMaster.getAnalog(okapi::ControllerAnalog::rightX) * 600;
		joyRY = sensors::controllerMaster.getAnalog(okapi::ControllerAnalog::rightY) * 600;

		//clamp joy values so that 0 is possible at the center and get rid of any extra slack in the joys.
		//I could make this faster with some bit trickery.
		if (std::abs(joyLY) < 10) 
			joyLY = 0;
		if (std::abs(joyRY) < 10) 
			joyRY = 0;
		if (std::abs(joyLX) < 300) 
			joyLX = 0;
		if (std::abs(joyRY) < 300) 
			joyRY = 0;

		// set motor speed and do tank drive calculations
		strifeVal = (joyLX + joyRX) / 2;
		setDriveVelocity(joyLY + strifeVal, joyRY - strifeVal, joyLY - strifeVal, joyRY + strifeVal);
		//LF + SD, RF - SD, LF - SD, RF + SD
	}

	void control(int input)
	{
		//needs implementation.
	}

	void setBrakeMode(okapi::Motor::brakeMode b) 
	{
		front_left_motor.setBrakeMode(b);
		front_right_motor.setBrakeMode(b);
		back_left_motor.setBrakeMode(b);
		back_right_motor.setBrakeMode(b);
	}

	void setDriveVelocity(int v1, int v2, int v3, int v4) 
	{
		front_left_motor.moveVelocity(v1);
		front_right_motor.moveVelocity(v2);
		back_left_motor.moveVelocity(v3);
		back_right_motor.moveVelocity(v4);
	}
}
