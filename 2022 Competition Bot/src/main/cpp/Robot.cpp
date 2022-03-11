// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "cameraserver/CameraServer.h"


void Robot::RobotInit()
      {
        frc::CameraServer::StartAutomaticCapture();
      }
void Robot::RobotPeriodic() {}

//+++++++++++++++++++++++++++++++++++++++++++++

void Robot::AutonomousInit() 
      {

      } 

void Robot::AutonomousPeriodic() 
      {
        botControl.autoRun();

      }

//+++++++++++++++++++++++++++++++++++++++++++++

void Robot::TeleopInit() 
      {
        botControl.intake.intakeArmEncoder.SetPosition(0.0);
        botControl.intake.clawEncoder.SetPosition(0.0);
        botControl.intake.initIntakePID();

        botControl.climber.hookArmEncoder.SetPosition(0.0);
        botControl.climber.winchEncoder.SetPosition(0.0);
        botControl.climber.initClimbPID();
      }

void Robot::TeleopPeriodic() 
      {
        if(teleRunning)
          {
            teleRunning = botControl.teleRun();
          }
        else
          {
            botControl.endGameRun();
          }
      }

//+++++++++++++++++++++++++++++++++++++++++++++

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

//+++++++++++++++++++++++++++++++++++++++++++++

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

//+++++++++++++++++++++++++++++++++++++++++++++

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
