// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "RightSwitchExchangeAuto.h"
#include "AutoDrive.h"
#include "AutoDriveTimed.h"
#include "AutoCurve.h"
#include "SetKirby.h"
#include "WaveWait.h"
#include "AutoRotate.h"
#include "SetElbow.h"
#include "SetKirbyKlaw.h"
#include "SetKirby.h"
#include "AutoDriveWithVision.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RightSwitchExchangeAuto::RightSwitchExchangeAuto() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

//	//Drive forward to switch
	AddSequential (new AutoCurve(-0.5, 23));
	AddSequential(new WaveWait(1));
	AddSequential(new AutoDrive(-50, -0.8, 20));
	AddSequential(new WaveWait(1));
	AddSequential(new AutoDrive(-20, -0.8, 0, 1));
//
//	//Place cube
//	AddSequential(new SetElbow(30));
//	AddSequential(new SetKirby(-0.6, .5));

//	//back up to grab new cube
//	AddSequential(new WaveWait(.5));
//	AddSequential(new AutoDrive(40, 0.8, 85));
////	AddSequential(new WaveWait(.5));
////	//AddSequential(new AutoDrive(15, 0.8, 55));
//	AddSequential(new WaveWait(0.25));
//	//AddSequential(new AutoRotate(0));
//	AddSequential(new AutoDrive(22, 0.4, 0));
//	AddSequential(new WaveWait(1));
////	AddParallel(new SetElbow(160));
////	AddSequential(new WaveWait(0.25));
//
//	AddSequential(new AutoDriveWithVision(-40, -0.4, 3));
//	AddSequential(new AutoRotate(0));
//	AddSequential(new AutoDriveWithVision(-5, -0.2, 2));
	//AddSequential(new AutoDrive(-25, -0.8, 0, 1));
	//AddSequential(new AutoDriveWithVision(1));

	//Grab cube
//	AddSequential(new SetKirbyKlaw(true));
//	AddSequential(new AutoDrive(-20, -0.5, 0));
//	AddSequential(new WaveWait(0.25));
//	AddSequential(new SetKirbyKlaw(false));
//	//AddSequential(new AutoDriveWithVision(.1, 0, 1));
//	AddSequential(new SetKirby(0.5, 0.5));
//
//	//Turn to face switch
//	AddSequential(new AutoDrive(20, 0.5, 0));
//	AddParallel(new SetElbow(30));
//	AddSequential(new AutoCurve(0.3, 180));

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
                      // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }
