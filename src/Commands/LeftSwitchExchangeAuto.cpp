// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "LeftSwitchExchangeAuto.h"
#include "AutoDrive.h"
#include "AutoDriveTimed.h"
#include "AutoCurve.h"
#include "SetElbow.h"
#include "SetKirby.h"
#include "WaveWait.h"
#include "AutoRotate.h"
#include "SetKirbyKlaw.h"
#include "AutoDriveWithVisionL.h"


LeftSwitchExchangeAuto::LeftSwitchExchangeAuto() {


	//Drive forward to switch
	AddSequential (new AutoCurve(-0.5, -33));
	AddSequential(new AutoDrive(-50, -0.8, -33));
	AddSequential(new AutoDriveTimed(-0.5, 0, .35));
	AddSequential(new WaveWait(1));
//
//	//Place cube
//	AddSequential(new SetElbow(30));
//	AddSequential(new SetKirby(-0.6, .5));

	//Back up and grab cube from exchange
	AddSequential(new AutoRotate(-40));
	AddSequential(new AutoDrive(35, 0.8, -40));
	AddSequential(new WaveWait(.25));
	AddSequential(new AutoDrive(15, 0.4, 0));
	AddSequential(new WaveWait(1));
	AddSequential(new AutoDriveWithVisionL(-40, -0.4, 3));
	AddSequential(new AutoRotate(0));
	AddSequential(new WaveWait(1));
	//AddSequential(new AutoDriveWithVisionL(-5, -0.2, 1));

	AddSequential(new AutoDriveTimed(-0.5, 0, 0.8));
	AddSequential(new AutoDrive(15, 0.8, 0));
	AddSequential(new AutoRotate(-38));
	AddSequential(new WaveWait(1));
	AddSequential(new AutoCurve(-0.5, -38));
	AddSequential(new AutoDrive(-40, -0.8, -38));
	AddSequential(new WaveWait(1));
	AddSequential(new AutoRotate(0));
	AddSequential(new AutoDriveTimed(-0.5, 0, 0.5));



//	AddSequential(new AutoCurve(-0.7, -35));
//	AddSequential(new WaveWait(.5));
//	AddSequential(new AutoDrive(35, 0.8, 0));
//	AddSequential(new WaveWait(0.25));
//	AddSequential(new AutoCurve(0.3, 10));
//	AddParallel(new SetElbow(160));
//	AddSequential(new WaveWait(0.25));

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


 }
