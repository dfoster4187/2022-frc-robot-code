

#pragma once
#include <iostream>
#include <Controller.h>
#include <DriveTrain.h>
#include <IntakeClass.h>
#include <ClimbClass.h>
#include <ClawClass.h>

class  ChaosHub
{
public: 

void autoRun();

bool teleRun();

void endGameRun();

Controller drvController;
//Controller::JoyStickData drvControllerData;
Controller::gameControllerData drvControllerData;

Controller opController;
Controller::gameControllerData opControllerData;

IntakeClass intake;

DriveTrain botDrive;

ClimbClass climber;

ClawClass claw;

bool intakeModeUp = true;
bool teleGame = true;
bool drvEndgameReady = false;
bool opEndgameReady = false;

bool doStepOne = false;
bool doStepTwo = false;
bool doStepThree = false;
bool doStepFour = false;
bool doStepFive = false;
bool doStepSix = false;
bool doStepSeven = false;
bool doStepEight = false;
bool doStepNine = false;

bool stepOneCompleted = false;
bool stepTwoCompleted = false;
bool stepThreeCompleted = false;
bool stepFourCompleted = false;
bool stepFiveCompleted = false;
bool stepSixCompleted = false;
bool stepSevenCompleted = false;
bool stepEightCompleted = false;
bool stepNineCompleted = false;

bool firstExtendCompleted = false;
bool firstBarContacted = false;
bool firstBarGrabbed = false;
bool firstRetractCompleted = false;
bool firstClawClosed = false;

bool secondExtend_A_Completed = false;
bool secondExtend_B_Completed = false;
bool secondBarContacted = false;
bool secondBarGrabbed = false;
bool secondRetractCompleted = false;
bool secondClawClosed = false;

};  