
#pragma once

#include <frc/Joystick.h>

class  Controller
{
public: 

  struct JoyStickData
    {
       double YAxis      = 0.0;
       double XAxis      = 0.0;
       double twistAxis  = 0.0;
       double sliderAxis = 0.0;
       bool   trigger    = false;
       bool   button8    = false;
    };

  struct gameControllerData
    {
      double leftTrigger     = 0.0;
      double rightTrigger    = 0.0;
      double leftStickYAxis  = 0.0;
      double rightStickYAxis = 0.0;
      int    dPad            = -1;
      bool   aButton         = false;
      bool   bButton         = false;
      bool   xButton         = false;
      bool   yButton         = false;
      bool   leftBumper      = false;
      bool   rightBumper     = false;
      bool   startButton     = false;
    };
  
JoyStickData X3dStickData;

frc::Joystick X3dStick{0};

JoyStickData readX3dStick();
  
gameControllerData xBoxControllerData;

frc::Joystick xBoxController0{0};

gameControllerData readxBoxController0();

frc::Joystick xBoxController1{1};
      
gameControllerData readxBoxController1();

}; //end class controller