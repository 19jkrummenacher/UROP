#include "object-config.hpp"
#include "main.h"



namespace drive
{
	okapi::MotorGroup front_left_motor{
		{okapi::Motor(4, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
		okapi::Motor(3, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
	okapi::MotorGroup back_left_motor{
		{okapi::Motor(2, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
		okapi::Motor(1, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
	okapi::MotorGroup front_right_motor{
		{okapi::Motor(15, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
		okapi::Motor(14, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};
	okapi::MotorGroup back_right_motor{
		{okapi::Motor(13, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
		okapi::Motor(12, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};

}

namespace sensors
{
	okapi::Controller controllerMaster(okapi::ControllerId::master);
	pros::Optical frontOptical(5);
	pros::Optical backOptical(9);

	pros::ADIAnalogIn topLineTracker ('A');
	pros::ADIAnalogIn midLineTracker ('B');
	pros::ADIAnalogIn bottomLineTracker ('C');

	okapi::ControllerButton intake = controllerMaster[okapi::ControllerDigital::R1];
	okapi::ControllerButton outTake = controllerMaster[okapi::ControllerDigital::R2];
	okapi::ControllerButton outChute = controllerMaster[okapi::ControllerDigital::L1];
	okapi::ControllerButton fire = controllerMaster[okapi::ControllerDigital::L2];
	okapi::ControllerButton clearFeed = controllerMaster[okapi::ControllerDigital::down];
	okapi::ControllerButton brake = controllerMaster[okapi::ControllerDigital::B];
}

namespace intake
{
	okapi::MotorGroup motors{
		{okapi::Motor(10, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees),
		okapi::Motor(20, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees)}};

}

namespace feed
{
	okapi::Motor frontFeed(6, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
	okapi::Motor backFeed(16, true, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
	okapi::Motor topFeed(7, false, okapi::AbstractMotor::gearset::blue, okapi::Motor::encoderUnits::degrees);
	
}
