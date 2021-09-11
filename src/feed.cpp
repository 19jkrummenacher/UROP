#include "feed.hpp"
#include "main.h"

namespace feed
{

	void control()
	{
		
		if(sensors::fire.isPressed())
			fireFeed();
		else if(sensors::outChute.isPressed())
			outChute();
		else if(sensors::intake.isPressed() || sensors::outTake.isPressed())
			inFeed();
		else if(sensors::clearFeed.isPressed())
			clearFeed();
		else
			stopFeed();
	}

	void control(int input)
	{
		switch(input)
		{
			case 0:
				stopFeed();
				break;
			case 1:
				fireFeed();
				break;
			case 2:
				clearFeed();
				break;
			case 3:
				inFeed();
				break;
			case 4:
				outChute();
				break;
			default:
			stopFeed();
		}

	}

	void fireFeed()
	{
		frontFeed.moveVoltage(12000);
		backFeed.moveVoltage(12000);
		topFeed.moveVoltage(12000);
	}

	void stopFeed()
	{
		frontFeed.moveVoltage(0);
		backFeed.moveVoltage(0);
		topFeed.moveVoltage(0);
	}

	void clearFeed()
	{
		frontFeed.moveVoltage(-12000);
		backFeed.moveVoltage(-12000);
		topFeed.moveVoltage(-12000);
	}

	void inFeed()
	{
		frontFeed.moveVoltage(12000);
		backFeed.moveVoltage(12000);
		topFeed.moveVoltage(0);
	}

	void outChute()
	{
		frontFeed.moveVoltage(12000);
		backFeed.moveVoltage(-12000);
		topFeed.moveVoltage(0);
	}
}
