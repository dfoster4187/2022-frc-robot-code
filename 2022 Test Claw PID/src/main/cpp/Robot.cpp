// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit()
      {
        clawMotor.Set(0.0);           // Stop testMotor
        clawEncoder.SetPosition(0.0); // Zero-out testEncoder

        testCounter = 0;


        // position PID settings

        clawPIDController.SetP(0.1);
        clawPIDController.SetI(0);
        clawPIDController.SetD(0);
        clawPIDController.SetIZone(0);
        clawPIDController.SetFF(0);
        clawPIDController.SetOutputRange(-0.2, 0.2);

        clawMotorSetPoint1 = 5.0;

      }
      


void Robot::TeleopPeriodic()
      {
        openButton  = zeroController.GetRawButton(1);
        closeButton = zeroController.GetRawButton(2); 
        setButton   = zeroController.GetRawButton(3);
        freeButton  = zeroController.GetRawButton(4);

        clawEncPOS  = clawEncoder.GetPosition();

        if (setButton)
          {
            clawPIDController.SetReference(clawMotorSetPoint1, rev::CANSparkMax::ControlType::kPosition);
            okayToMove = false;
          }
        else if (freeButton)
          {
            clawMotor.Set(0.0);
            okayToMove = true;
          }

        if (okayToMove)
          {
            if (openButton)
              {
                clawMotor.Set(-0.2);
              }
            else if (closeButton)
              {
                clawMotor.Set(0.2);
              }
            else
              {
                clawMotor.Set(0.0);
              }
          }

/*
        if(testCounter == 0)
          {
            testPIDController.SetReference(testMotorSetPoint1, rev::CANSparkMax::ControlType::kPosition);
            sixPIDController.SetReference(sixMotorSetPoint1, rev::CANSparkMax::ControlType::kPosition);
            testCounter++;           
          }
        else if((testEncPOS < (testMotorSetPoint1)) or (sixEncPOS < (sixMotorSetPoint1)))
                {}         
        else if((testEncPOS < (testMotorSetPoint1 + 1)) and (testEncPOS > (testMotorSetPoint1 - 1))
                and (sixEncPOS < (sixMotorSetPoint1 + 1)) and (sixEncPOS > (sixMotorSetPoint1 - 1))
                and testCounter < 500)
                {
                  testCounter++;
                } 
*/

        std::cout << "Enc = " << clawEncPOS << " / SetPt = " << clawMotorSetPoint1 << std::endl;

      } // end teleopPeriodic()

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
