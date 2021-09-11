#pragma once
#include "main.h"
#include "okapi/api.hpp"



namespace drive
{
	extern okapi::MotorGroup front_left_motor;
	extern okapi::MotorGroup front_right_motor;
	extern okapi::MotorGroup back_left_motor;
	extern okapi::MotorGroup back_right_motor;

} // namespace drive

namespace sensors
{
	extern okapi::Controller controllerMaster;
	extern pros::Optical frontOptical;
	extern pros::Optical backOptical;

	extern pros::ADIAnalogIn topLineTracker;
	extern pros::ADIAnalogIn midLineTracker;
	extern pros::ADIAnalogIn bottomLineTracker;

	extern okapi::ControllerButton intake;
	extern okapi::ControllerButton outTake;
	extern okapi::ControllerButton outChute;
	extern okapi::ControllerButton fire;
	extern okapi::ControllerButton clearFeed;
	extern okapi::ControllerButton brake;
}

namespace intake
{
	extern okapi::MotorGroup motors;

} // namespace intake

namespace feed
{
	extern okapi::Motor frontFeed;
	extern okapi::Motor backFeed;
	extern okapi::Motor topFeed;

} // namespace feed
