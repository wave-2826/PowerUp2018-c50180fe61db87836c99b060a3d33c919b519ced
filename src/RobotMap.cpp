// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

//solenoids
int driveShift = 0;
int ironCrossDeploy = 2;
int tRexDeploy = 1;
int klaw = 3;


//digital input
int intakeSwitch = 6;
int elbowZero = 4;
int elevatorZero = 7; //This is what we are using
int elevatorHigh = 5;

//encoder
int driveWheelSize = 6; //drive wheel
double distancePerPulse = ((driveWheelSize * 3.14159) / 256);

//This is distance per pulse for determining elevator height. To determine this number, start with the elevator in the lowest position
//and read the encoder count. Then raise the elevator to it's known highest height and read the encoder count again. The formula for
//the calibration value is then:  Distance Traveled / (High Height Encoder Count - Low Height Encoder Count)
const double c_elevatorCalibration = 1.0;


//This is angle per pulse for determining elbow angle. To determine this number, start with the elbow at a knwon angle
//and read the encoder count. Then move the elbow to a second known angle and read the encoder count again. The formula for
//the calibration value is then:  (Final Angle - Start Angle) / (Final Encoder Count - Start Encoder Count)
const double c_elbowCalibration = 1.0;

#define CompBot

#ifdef TestChassis
int CANTalon_driveDriveLeft1	    = 16;
int CANTalon_driveDriveLeft2	    = 17;
int CANTalon_driveDriveLeft3	    = 16;
int CANTalon_driveDriveRight1		= 6;
int CANTalon_driveDriveRight2		= 26;
int CANTalon_driveDriveRight3		= 16;
int CANTalon_elbowElbowRight		= 16;
int CANTalon_elbowElbowLeft			= 16;
int CANTalon_KirbyIntakeRight		= 14;
int CANTalon_KirbyIntakeLeft		= 2;
int CANTalon_elevatorElevatorRight	= 16;
int CANTalon_elevatorElevatorLeft	= 16;
#endif

#ifdef PracticeBot
int CANTalon_driveDriveLeft1	    = 35;
int CANTalon_driveDriveLeft2	    = 41;
int CANTalon_driveDriveLeft3	    = 29;
int CANTalon_driveDriveRight1		= 28;
int CANTalon_driveDriveRight2		= 34;
int CANTalon_driveDriveRight3		= 36;
int CANTalon_elbowElbowRight		= 33;
int CANTalon_elbowElbowLeft			= 30;
int CANTalon_KirbyIntakeRight		= 32;
int CANTalon_KirbyIntakeLeft		= 8;
int CANTalon_elevatorElevatorRight	= 20;
int CANTalon_elevatorElevatorLeft	= 31;
#endif


#ifdef CompBot
int CANTalon_driveDriveLeft1	    = 3;
int CANTalon_driveDriveLeft2	    = 40;
int CANTalon_driveDriveLeft3	    = 39;
int CANTalon_driveDriveRight1		= 13;
int CANTalon_driveDriveRight2		= 25;
int CANTalon_driveDriveRight3		= 37;
int CANTalon_elbowElbowRight		= 23;
int CANTalon_elbowElbowLeft			= 27;
int CANTalon_KirbyIntakeRight		= 24;
int CANTalon_KirbyIntakeLeft		= 38;
int CANTalon_elevatorElevatorRight	= 18;
int CANTalon_elevatorElevatorLeft	= 9;
#endif


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<frc::Solenoid> RobotMap::driveShifter;
std::shared_ptr<WPI_TalonSRX> RobotMap::kirbyKirbyRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::kirbyKirbyLeft;
std::shared_ptr<frc::DigitalInput> RobotMap::kirbyKirbyFull;
std::shared_ptr<frc::Solenoid> RobotMap::kirbyKirbyKlaw;
std::shared_ptr<frc::Solenoid> RobotMap::ironCrossDeployCross;
std::shared_ptr<frc::Solenoid> RobotMap::ironCrossDeployTRexArms;
//std::shared_ptr<frc::Encoder> RobotMap::elevatorElevatorEncoder;
std::shared_ptr<WPI_TalonSRX> RobotMap::elevatorElevatorRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::elevatorElevatorLeft;
std::shared_ptr<frc::DigitalInput> RobotMap::elevatorElevatorZero;
std::shared_ptr<frc::DigitalInput> RobotMap::elevatorElevatorHigh;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::elevatorLiftMotors;
std::shared_ptr<WPI_TalonSRX> RobotMap::elbowElbowRight;
std::shared_ptr<WPI_TalonSRX> RobotMap::elbowElbowLeft;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::elbowElbowRotate;
//std::shared_ptr<frc::Encoder> RobotMap::elbowElbowPosition;
std::shared_ptr<frc::DigitalInput> RobotMap::elbowElbowZero;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivePIDLeft1;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivePIDLeft2;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivePIDLeft3;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::drivePIDLeftDriveGroup;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivePIDRight1;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivePIDRight2;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivePIDRight3;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::drivePIDRightDriveGroup;
std::shared_ptr<frc::DifferentialDrive> RobotMap::drivePIDDiffDrive;
std::shared_ptr<frc::Encoder> RobotMap::drivePIDLeftEncoder;
std::shared_ptr<frc::Encoder> RobotMap::drivePIDRightEncoder;
std::shared_ptr<frc::Solenoid> RobotMap::drivePIDShifter;
std::shared_ptr<Compressor> RobotMap::compressorSubsystemCompressor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {

    kirbyKirbyRight.reset(new WPI_TalonSRX(CANTalon_KirbyIntakeLeft));
    
    
    kirbyKirbyLeft.reset(new WPI_TalonSRX(CANTalon_KirbyIntakeRight));
    
    
    kirbyKirbyFull.reset(new frc::DigitalInput(intakeSwitch));
    kirbyKirbyFull.get()->SetName("Kirby");
    
    kirbyKirbyKlaw.reset(new frc::Solenoid(0, klaw));

    ironCrossDeployCross.reset(new frc::Solenoid(0, ironCrossDeploy));
    ironCrossDeployTRexArms.reset(new frc::Solenoid(0, tRexDeploy));
    ironCrossDeployCross.get()->SetName("IronCross");
    ironCrossDeployTRexArms.get()->SetName("TRexArms");
    
//    elevatorElevatorEncoder.reset(new frc::Encoder(7, 8, false, frc::Encoder::k4X));
//    elevatorElevatorEncoder->SetDistancePerPulse(c_elevatorCalibration);
//    elevatorElevatorEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);

    elevatorElevatorZero.reset(new frc::DigitalInput(elevatorZero));
    elevatorElevatorHigh.reset(new frc::DigitalInput(elevatorHigh));

    elevatorElevatorRight.reset(new WPI_TalonSRX(CANTalon_elevatorElevatorRight));

    
    elevatorElevatorLeft.reset(new WPI_TalonSRX(CANTalon_elevatorElevatorLeft));
    
    
    elevatorLiftMotors = std::make_shared<frc::SpeedControllerGroup>(*elevatorElevatorRight, *elevatorElevatorLeft  );
    
    elbowElbowRight.reset(new WPI_TalonSRX(CANTalon_elbowElbowRight));
    
    
    elbowElbowLeft.reset(new WPI_TalonSRX(CANTalon_elbowElbowLeft));
    
    
    elbowElbowRotate = std::make_shared<frc::SpeedControllerGroup>(*elbowElbowRight, *elbowElbowLeft);
    
//    elbowElbowPosition.reset(new frc::Encoder(29, 30, false, frc::Encoder::k4X));
//    //lw->AddSensor("Elbow", "ElbowPosition", elbowElbowPosition);
//    elbowElbowPosition->SetDistancePerPulse(c_elbowCalibration);
//    elbowElbowPosition->SetPIDSourceType(frc::PIDSourceType::kDisplacement);

    elbowElbowZero.reset(new frc::DigitalInput(elbowZero));
    
    drivePIDLeft1.reset(new WPI_TalonSRX(CANTalon_driveDriveLeft1));

    
    drivePIDLeft2.reset(new WPI_TalonSRX(CANTalon_driveDriveLeft2));
    
    
    drivePIDLeft3.reset(new WPI_TalonSRX(CANTalon_driveDriveLeft3));
    
    
    drivePIDLeftDriveGroup = std::make_shared<frc::SpeedControllerGroup>(*drivePIDLeft1, *drivePIDLeft2 , *drivePIDLeft3 );
    
    drivePIDRight1.reset(new WPI_TalonSRX(CANTalon_driveDriveRight1));
    
    
    drivePIDRight2.reset(new WPI_TalonSRX(CANTalon_driveDriveRight2));
    
    
    drivePIDRight3.reset(new WPI_TalonSRX(CANTalon_driveDriveRight3));
    
    
    drivePIDRightDriveGroup = std::make_shared<frc::SpeedControllerGroup>(*drivePIDRight1, *drivePIDRight2 , *drivePIDRight3 );
    
    drivePIDDiffDrive.reset(new frc::DifferentialDrive(*drivePIDLeftDriveGroup, *drivePIDRightDriveGroup));
    drivePIDDiffDrive->SetSafetyEnabled(true);
        drivePIDDiffDrive->SetExpiration(0.1);
        drivePIDDiffDrive->SetMaxOutput(1.0);

    drivePIDLeftEncoder.reset(new frc::Encoder(2, 3, false, frc::Encoder::k4X));
    drivePIDLeftEncoder->SetDistancePerPulse(1.0);
    drivePIDLeftEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
    drivePIDRightEncoder.reset(new frc::Encoder(0, 1, false, frc::Encoder::k4X));
    drivePIDRightEncoder->SetDistancePerPulse(1.0);
    drivePIDRightEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
    drivePIDShifter.reset(new frc::Solenoid(0, driveShift));
    
    compressorSubsystemCompressor.reset(new Compressor(0));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
