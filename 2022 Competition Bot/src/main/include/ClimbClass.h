
#pragma once

#include <rev/CANSparkMax.h>
#include <chrono>

class  ClimbClass
{
private: 

  bool hookPlaced = false;

public: 

  rev::CANSparkMax winchMotor{6, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController winchPIDController = winchMotor.GetPIDController();
  rev::SparkMaxRelativeEncoder winchEncoder = winchMotor.GetEncoder();

  rev::CANSparkMax hookArmMotor{7, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController hookArmPIDController = hookArmMotor.GetPIDController();
  rev::SparkMaxRelativeEncoder hookArmEncoder = hookArmMotor.GetEncoder();

void initClimbPID();

bool hookPlacement(double, double);

void retract();

void readEncoder();

void stopAll();

void runHookArm(double);

void runWinch(double); 

int placementCount = 0;

double firstArmSetPoint = 18.0;
double firstWinchSetPoint = 96.0;

private:
const double CONST_MAX_TIME_MS = 200.0f;   // 200 ms = 5Hz of text update
double timeAtLastEpoch = 0.0f;


};  