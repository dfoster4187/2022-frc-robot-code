
#include <ChaosHub.h>

void ChaosHub::autoRun()
       {
           
       }
       

bool ChaosHub::teleRun()
       {
     

         drvControllerData = drvController.readxBoxController0();

         opControllerData = opController.readxBoxController1();

//          botDrive.stickDrive(drvControllerData.YAxis, drvControllerData.twistAxis);

         botDrive.xBoxDrive(drvControllerData.leftStickYAxis, drvControllerData.rightStickYAxis, drvControllerData.leftBumper);

         climber.readEncoder();

         if (drvControllerData.startButton)
            {
               drvEndgameReady = true;
            }

         if (opControllerData.startButton)
            {
               opEndgameReady = true;
            }

         if (drvEndgameReady and opEndgameReady)
            {
               teleGame = false;
            }

         if (opControllerData.dPad == 0)
            {
               intakeModeUp = true;
            }
         else if(opControllerData.dPad == 180)
            {
               intakeModeUp = false;
            } 


         if (intakeModeUp)
            {
               intake.up(opControllerData.rightTrigger);
            }
         else
            {
               if (opControllerData.leftTrigger < 0.2)
                  {
                     opControllerData.leftTrigger = 0.0;
                  }
               intake.down(drvControllerData.rightTrigger, drvControllerData.leftTrigger);       
            }

// intake.readEncoder();
         return teleGame;
       } //end telerun() 



void ChaosHub::endGameRun()
      {
         drvControllerData = drvController.readxBoxController0();

         opControllerData = opController.readxBoxController1();

         botDrive.xBoxDrive(drvControllerData.leftStickYAxis, drvControllerData.rightStickYAxis, drvControllerData.leftBumper);         

         climber.readEncoder();
         intake.readEncoder();


         if(opControllerData.xButton and (not stepOneCompleted))
            {
               doStepOne = true;
            }  
         else if(drvControllerData.xButton and (not stepTwoCompleted) and stepOneCompleted)
            {
               doStepTwo = true;

            }
         else if(opControllerData.xButton and (not stepThreeCompleted) and stepTwoCompleted)
            {
               doStepThree = true;
            }
         else if(drvControllerData.xButton and (not stepFourCompleted) and stepThreeCompleted)
            {
               doStepFour = true;
            }
         else if(opControllerData.xButton and (not stepFiveCompleted) and stepFourCompleted)
            {
               doStepFive = true;
            }
         else if(drvControllerData.xButton and (not stepSixCompleted) and stepFiveCompleted)
            {
               doStepSix = true;
            }
         else if(opControllerData.xButton and (not stepSevenCompleted) and stepSixCompleted)
            {
               doStepSeven = true;
            }
         else if(drvControllerData.xButton and (not stepEightCompleted) and stepSevenCompleted)
            {
               doStepEight = true;
            }
         else if(opControllerData.xButton and (not stepNineCompleted) and stepEightCompleted)
            {
               doStepNine = true;
            }

         if (doStepOne) 
            { 
 //              climber.stopAll();
               intake.openClaw();             
/*                
               if (not firstExtendCompleted)
                  {
                     firstExtendCompleted = climber.hookPlacement(18.0, 96.0);
                  }
               else if(not firstBarContacted)
                  {
                     firstBarContacted = climber.hookPlacement(20.0, 96.0);
                  }
               else if(not firstBarGrabbed)
                  {
                     firstBarGrabbed = climber.hookPlacement(20.0, 75.0);
                  }
               else
                  {
                     stepOneCompleted = true;
                     doStepOne = false;
                  }
*/               
            }
         else if (doStepTwo)
            {
//               intake.closeClaw();
/*
               if (not firstRetractCompleted)
                  {
                     firstRetractCompleted = climber.hookPlacement(10.0, 0.0);
                  }
               else if(not firstClawClosed)
                  {
                     firstClawClosed = intake.closeClaw();
                  }
               else
                  {
                     stepTwoCompleted = true;
                     doStepTwo = false;
                  }
*/
            }
         else if (doStepThree)
            {
               climber.stopAll();
 /*              
               if (not secondExtend_A_Completed)
                  {
                     secondExtend_A_Completed = climber.hookPlacement(10.0, 64.0);
                  }
                if (not secondExtend_B_Completed)
                  {
                     secondExtend_B_Completed = climber.hookPlacement(16.0, 96.0);
                  }                 
               else if(not secondBarContacted)
                  {
                     secondBarContacted = climber.hookPlacement(17.0, 96.0);
                  }
               else if(not secondBarGrabbed)
                  {
                     secondBarGrabbed = climber.hookPlacement(17.0, 75.0);
                  }
               else
                  {
                     stepThreeCompleted = true;
                     doStepThree = false;
                  }
*/                 
            }
         
            
         if (opControllerData.leftBumper)
            {
               if ((opControllerData.rightStickYAxis < 0.5) and (opControllerData.rightStickYAxis > -0.5))
                  {
                     opControllerData.rightStickYAxis = 0.0;
                  }

               climber.runWinch(-opControllerData.rightStickYAxis);
            }


         if (opControllerData.rightBumper)
            {
               if ((opControllerData.leftStickYAxis < 0.5) and (opControllerData.leftStickYAxis > -0.5))
                  {
                     opControllerData.leftStickYAxis = 0.0;
                  }
                  
               climber.runHookArm(-opControllerData.leftStickYAxis * 0.2);
            }

         intake.runClaw(opControllerData.aButton,opControllerData.bButton);

      }//end endGameRun()

