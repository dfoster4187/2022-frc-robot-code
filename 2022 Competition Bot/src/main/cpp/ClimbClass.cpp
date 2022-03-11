
#include <ClimbClass.h>
#include <iostream>

void ClimbClass::initClimbPID()
       {
        // position PID settings
        hookArmPIDController.SetP(0.1);
        hookArmPIDController.SetI(0);
        hookArmPIDController.SetD(0);
        hookArmPIDController.SetIZone(0);
        hookArmPIDController.SetFF(0);
        hookArmPIDController.SetOutputRange(-0.2, 0.2);

        winchPIDController.SetP(0.1);
        winchPIDController.SetI(0);
        winchPIDController.SetD(0);
        winchPIDController.SetIZone(0);
        winchPIDController.SetFF(0);
        winchPIDController.SetOutputRange(-0.5, 0.5);
       }

bool ClimbClass::hookPlacement(double armSetPoint, double winchSetPoint)
      {
         hookPlaced = false;

         if (placementCount == 0)
            {
               hookArmPIDController.SetReference(armSetPoint, rev::CANSparkMax::ControlType::kPosition);
               winchPIDController.SetReference(winchSetPoint, rev::CANSparkMax::ControlType::kPosition);  
               placementCount++;
            }

         if ((hookArmEncoder.GetPosition() >   (armSetPoint -1))  and
             (hookArmEncoder.GetPosition() <   (armSetPoint +1))  and
             (winchEncoder.GetPosition()   > (winchSetPoint -1))  and
             (winchEncoder.GetPosition()   < (winchSetPoint +1)))          
               {
                  hookPlaced = true;
                  placementCount = 0;
               }
         return hookPlaced;

      } // end firstExtend()





void ClimbClass::readEncoder()
      { 
         const double currEpochTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
         const double currElapEpochTime = currEpochTime - timeAtLastEpoch;
         if (currElapEpochTime >= CONST_MAX_TIME_MS)
         {
            std::cout << "\n********\nNew Data\n";
            std::cout << "\nhookArm=\t" << hookArmEncoder.GetPosition();
            std::cout << "\nwinch=\t" << winchEncoder.GetPosition();
            std::cout << "\nTime since last Epoch=\t" << currElapEpochTime;
            timeAtLastEpoch = currEpochTime;
         }
      }//end readEncoder()


void ClimbClass::stopAll()     
      {
         hookArmMotor.Set(0.0);
         winchMotor.Set(0.0);
      }

void ClimbClass::runHookArm(double ArmSpeed)
      {
         hookArmMotor.Set(ArmSpeed);
      }




void ClimbClass::runWinch(double winchSpeed)
      {
         winchMotor.Set(winchSpeed);
      }