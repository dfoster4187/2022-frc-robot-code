
#pragma once

#include <frc/TimedRobot.h>
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;
  
  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  rev::CANSparkMax   oneSpark{1, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax   twoSpark{2, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax threeSpark{3, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax  fourSpark{4, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax  fiveSpark{5, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax   sixMotor{6, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax sevenMotor{7, rev::CANSparkMax::MotorType::kBrushless};

  rev::CANSparkMax  clawMotor{8, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController clawPIDController = clawMotor.GetPIDController();
  rev::SparkMaxRelativeEncoder clawEncoder = clawMotor.GetEncoder();

  frc::Joystick zeroController{0};

  int testCounter = 0; 

  double clawMotorSetPoint1 = 0.0;
  double clawEncPOS = 0.0;

  double testYAxis = 0.0;
  double sixMotorSetPoint1 = 0.0;
  double testRPMVelocity = 0.0;
  double sixEncPOS = 0.0;

  bool openButton  = false;
  bool closeButton = false;
  bool setButton   = false;
  bool freeButton  = false;
  bool okayToMove  = false;

};
