// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Elevator.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include <iostream>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

namespace{
	const double heightDivisor = 317.24;
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
Elevator::Elevator() : PIDSubsystem("Elevator", 0.07, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
   // GetPIDController()->SetContinuous(false);
 //   frc::LiveWindow::GetInstance()->AddActuator("Elevator", "PIDSubsystem Controller", GetPIDController());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
   // elevatorEncoder = RobotMap::elevatorElevatorEncoder;
    elevatorRight = RobotMap::elevatorElevatorRight;
    elevatorLeft = RobotMap::elevatorElevatorLeft;
    liftMotors = RobotMap::elevatorLiftMotors;
    elevatorZero = RobotMap::elevatorElevatorZero;
    elevatorHigh = RobotMap::elevatorElevatorHigh;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    //elevatorRight.get()->SetInverted(true);
    elevatorRight->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 50);
    //elevatorRight->ConfigContinuousCurrentLimit(0.8, 50);
    elevatorRight->ConfigPeakOutputReverse(-100, 50);
    elevatorRight->ConfigPeakOutputForward(100, 50);
    elevatorRight->SetSafetyEnabled(false);

    //elevatorLeft->ConfigContinuousCurrentLimit(0.8, 50);

    m_speed = 0;
    m_heightSet = false;

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.

    //Start with the PID disabled. To enable, call SetElevatorHeight()
    GetPIDController()->Disable();
}

double Elevator::ReturnPIDInput() {
    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
       // return elevatorEncoder->PIDGet();
	return GetHeight();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void Elevator::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
	if(output < -0.6){
		output = -0.6;
	}

	elevatorRight.get()->Set(-output);
	elevatorLeft.get()->Set(output);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
}

void Elevator::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Elevator::SetElevatorSpeed(double speed) {
	Disable();
	m_speed = speed;
	//SensorTriggered();
	if(m_speed < -0.7){
		m_speed = -0.7;
	}

	elevatorRight.get()->Set(-m_speed);
	elevatorLeft.get()->Set(m_speed);
}

double Elevator::GetHeight(){
	double encoderCount = elevatorRight->GetSensorCollection().GetQuadraturePosition();
	double distance = encoderCount/heightDivisor;
	return distance;
}

void Elevator::SetHeight(double height){

	m_heightSet = true;

	if(GetPIDController()->GetSetpoint() != height)
	{
		GetPIDController()->Disable();
		GetPIDController()->Reset();

		std::cout << "Set HEIGHT" << std::endl;

		GetPIDController()->SetSetpoint(height);
		GetPIDController()->Enable();
	}
}

void Elevator::SensorTriggered(){
	double setValue = 53.0*heightDivisor; //59 for comp bot
	if(IsSensorTripped()){
		std::cout << " ------------------------- Reset Sensor --------------------------- " << std::endl;
		elevatorRight->GetSensorCollection().SetQuadraturePosition(setValue, 50);
	}
}

bool Elevator::IsSensorTripped(){
	return !elevatorZero.get()->Get();
}

void Elevator::ZeroHeight(){
	elevatorRight->GetSensorCollection().SetQuadraturePosition(0, 50);
}

void Elevator::DisablePID(){
	GetPIDController()->Disable();
}
