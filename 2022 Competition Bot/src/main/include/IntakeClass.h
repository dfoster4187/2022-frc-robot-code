
#pragma once

#include <rev/CANSparkMax.h>
#include <frc/motorcontrol/Spark.h>

class  IntakeClass
{
private:

//  double intakeDownVelocity = -0.1;
//  double intakeUpVelocity = 0.23;
  
public: 

  rev::CANSparkMax intakeArmMotor{5, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder intakeArmEncoder = intakeArmMotor.GetEncoder();

  rev::CANSparkMax clawMotor{8, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController clawPIDController = clawMotor.GetPIDController();
  rev::SparkMaxRelativeEncoder clawEncoder = clawMotor.GetEncoder();

  frc::Spark intakeRollerMotor{0};

void initIntakePID();

void up(double);

void down(double, double);

void readEncoder();

void runClaw(bool, bool);

bool openClaw();

bool closeClaw();

void goGo();
void stopStop();

bool okayToShoot = false;
bool okayToIntake = false;
bool clawOpen = false;
bool clawClosed = false;

int openCount = 0;
int closeCount = 0;

double openSetPoint = -5.0;
double closeSetPoint = -3.0;

};  

