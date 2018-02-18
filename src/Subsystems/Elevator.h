// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "ctre/phoenix.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Elevator: public frc::PIDSubsystem {
 public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::Encoder> elevatorEncoder;
	std::shared_ptr<WPI_TalonSRX> elevatorRight;
	std::shared_ptr<WPI_TalonSRX> elevatorLeft;
	std::shared_ptr<frc::SpeedControllerGroup> liftMotors;
	std::shared_ptr<frc::DigitalInput> elevatorZero;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Elevator();
	double ReturnPIDInput() override;
	void UsePIDOutput(double output) override;
	void InitDefaultCommand() override;

	// Sets the speed of the elevator, positive numbers will make it go up.
	// Disables the PID. To re-enable the PID, call SetElevatorHeight()
	void SetElevatorSpeed(double speed);
	double GetHeight();
	void ZeroHeight();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
