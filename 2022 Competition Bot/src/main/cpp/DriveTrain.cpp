
#include <DriveTrain.h>


   void DriveTrain::stickDrive(double YAxis, double twistAxis)
          {
            if(twistAxis == 0)
            {
//                testMotor.Set(YAxis);
              leftFrontMotor.Set(YAxis);
              rightFrontMotor.Set(-YAxis);
              leftRearMotor.Set(YAxis);
              rightRearMotor.Set(-YAxis);

            }  
          else
            {
//                testMotor.Set(-twistAxis);
              leftFrontMotor.Set(-twistAxis);
              rightFrontMotor.Set(-twistAxis);
              leftRearMotor.Set(-twistAxis);
              rightRearMotor.Set(-twistAxis);     
         
            }  
          }// end stickDrive()

void DriveTrain::xBoxDrive(double leftYAxis, double rightYAxis, bool preciseDrive)
        {
          if (preciseDrive)
            {
              leftYAxis = leftYAxis * 0.1;
              rightYAxis = rightYAxis * 0.1;
            }
          leftFrontMotor.Set(leftYAxis);
          rightFrontMotor.Set(-rightYAxis);
          leftRearMotor.Set(leftYAxis);
          rightRearMotor.Set(-rightYAxis);         
        }