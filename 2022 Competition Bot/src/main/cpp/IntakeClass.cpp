
#include <IntakeClass.h>
#include <iostream>



void IntakeClass::initIntakePID()
       {
        clawPIDController.SetP(0.1);
        clawPIDController.SetI(0);
        clawPIDController.SetD(0);
        clawPIDController.SetIZone(0);
        clawPIDController.SetFF(0);
        clawPIDController.SetOutputRange(-0.2, 0.2);

       }



void IntakeClass::up(double trigger)
      {
      if ((intakeArmEncoder.GetPosition() < 0.0) and (clawEncoder.GetPosition() < 2.5))
          {
            if (clawEncoder.GetPosition() < 2.5)
              {
                clawMotor.Set(0.2);
              }
            else
              {
                clawMotor.Set(0.0);
              }
          }              
        else if ((intakeArmEncoder.GetPosition() < 0.5) and (clawEncoder.GetPosition() >= 2.5))
          {
            clawMotor.Set(0.0);
            intakeRollerMotor.Set(0.0);
            if (intakeArmEncoder.GetPosition() < -2)
              {
                intakeArmMotor.Set(0.4);
              }
            else
              {
                intakeArmMotor.Set(0.15);
              }
          }
        else if ((clawEncoder.GetPosition() > 0.0) and (intakeArmEncoder.GetPosition() >= 0.2))
          {
            intakeArmMotor.Set(.15);
            clawMotor.Set(-0.2);         
          }
        else 
          {
            clawMotor.Set(0.0);
            intakeArmMotor.Set(0.0);
            if (trigger > 0.8)
              {
                intakeRollerMotor.Set(-1.0);
              }
          }
/*
         if ((intakeArmEncoder.GetPosition() < 12.0) and (clawEncoder.GetPosition() < -0.5))
           {
             if (clawEncoder.GetPosition() < -0.5)
               {
                  clawMotor.Set(0.2);
               }
             else
               {
                  clawMotor.Set(0.0);
               }
           }              
         else if ((intakeArmEncoder.GetPosition() < 12.0) and (clawEncoder.GetPosition() >= -0.5))
           {
              clawMotor.Set(0.0);
              intakeRollerMotor.Set(0.0);
              if (intakeArmEncoder.GetPosition() < 10)
                {
                  intakeArmMotor.Set(0.23);
                }
              else
                {
                  intakeArmMotor.Set(0.15);
                }
           }
         else if ((clawEncoder.GetPosition() > -3.0) and (intakeArmEncoder.GetPosition() >= 12.0))
           {
              intakeArmMotor.Set(.15);
              clawMotor.Set(-0.2);         
           }
         else 
           {
             clawMotor.Set(0.0);
             intakeArmMotor.Set(0.0); 
           }
*/
       } // end up()




void IntakeClass::down(double speed, double reverseSpeed)
       {
          intakeArmMotor.Set(0.0);
          okayToShoot = false;
          okayToIntake = true;
          if (clawEncoder.GetPosition() < 1.0)
            {
                clawMotor.Set(0.2);            
            }
          else if (clawEncoder.GetPosition() < 2.5)
            {
                clawMotor.Set(0.2);
                intakeArmMotor.Set(-0.1);

            }
          else if (intakeArmEncoder.GetPosition() > -10.0)
            {
                clawMotor.Set(0.0);
                intakeArmMotor.Set(-0.1);
            }
          else
            {
              clawMotor.Set(0.0);
              intakeArmMotor.Set(0.0);
              
              if (reverseSpeed > 0.8)
                {
                  intakeRollerMotor.Set(-reverseSpeed);
                }
              else
                {
                  intakeRollerMotor.Set(speed);
                }
            }
       }



void IntakeClass::readEncoder()
       {
//         std::cout << "arm = " << intakeArmEncoder.GetPosition();
         std::cout << " / claw = " << clawEncoder.GetPosition() << std::endl;         
       }



void IntakeClass::runClaw( bool a, bool b)
      {
        if(a)
          {
              clawMotor.Set(0.2);
          }
      else if(b)
          {
              clawMotor.Set(-0.2);
          }
      else
          {
              clawMotor.Set(0.0);
          }
      }

bool IntakeClass::openClaw()
      {
         clawOpen = false;

         if (openCount == 0)
            {
              std::cout << "stPT=" << openSetPoint;
               clawPIDController.SetReference(openSetPoint, rev::CANSparkMax::ControlType::kPosition); 
               openCount++;
            }

         if ((clawEncoder.GetPosition() >   (openSetPoint -1))  and
             (clawEncoder.GetPosition() <   (openSetPoint +1)))        
               {
                  clawOpen = true;
                  openCount = 0;
               }

         return clawOpen;
      } // end openClaw()



bool IntakeClass::closeClaw()
      {
         clawClosed = false;

         if (closeCount == 0)
            {
               clawPIDController.SetReference(closeSetPoint, rev::CANSparkMax::ControlType::kPosition); 
               closeCount++;
            }

         if ((clawEncoder.GetPosition() >   (closeSetPoint -1))  and
             (clawEncoder.GetPosition() <   (closeSetPoint +1)))        
               {
                  clawClosed = true;
                  closeCount = 0;
               }
               
         return clawOpen;
      } // end openClaw()

void IntakeClass::goGo()
       {
          intakeArmMotor.Set(0.3);
       }



void IntakeClass::stopStop()
       {
          intakeArmMotor.Set(0.0);
       }