#include "intakes.hpp"
#include "main.h"

namespace intake
{
	void control()
	{
		if(sensors::intake.isPressed())
			intakeIn();
		else if(sensors::outTake.isPressed())
			intakeOut();
		else
			stopIntake();
	}

	void control(int input)
	{
		switch(input)
		{
			case 0:
				stopIntake();
				break;
			case 1:
				intakeIn();
				break;
			case 2:
				intakeOut();
				break;
			default:
				stopIntake();
			break;
		}

	}

	void intakeIn()
	{
		motors.moveVoltage(12000);
	}

	void stopIntake()
	{
		motors.moveVoltage(0);
	}
	
	void intakeOut()
	{
		motors.moveVoltage(-6000);
	}
}
