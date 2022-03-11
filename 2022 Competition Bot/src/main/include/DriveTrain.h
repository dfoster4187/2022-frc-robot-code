
#pragma once

#include <rev/CANSparkMax.h>

class  DriveTrain
{
public: 

void xBoxDrive(double, double, bool);

void stickDrive(double, double);

rev::CANSparkMax leftFrontMotor{1, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax rightFrontMotor{2, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax leftRearMotor{3, rev::CANSparkMax::MotorType::kBrushless};
rev::CANSparkMax rightRearMotor{4, rev::CANSparkMax::MotorType::kBrushless};

//  rev::CANSparkMax testMotor{10, rev::CANSparkMax::MotorType::kBrushless};

};  

