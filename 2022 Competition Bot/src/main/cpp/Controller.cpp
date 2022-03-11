
#include <Controller.h>

Controller::JoyStickData Controller::readX3dStick()
  {
    X3dStickData.YAxis      = X3dStick.GetRawAxis(1);
    X3dStickData.XAxis      = X3dStick.GetRawAxis(0);
    X3dStickData.twistAxis  = X3dStick.GetRawAxis(2);
    X3dStickData.sliderAxis = X3dStick.GetRawAxis(3);
    X3dStickData.trigger    = X3dStick.GetRawButton(1);

    if ((X3dStickData.YAxis < 0.2) and (X3dStickData.YAxis > -0.2))
      {
        X3dStickData.YAxis = 0.0;
      }
       
    if ((X3dStickData.twistAxis < 0.2) and (X3dStickData.twistAxis > -0.2))
      {
         X3dStickData.twistAxis = 0.0;
      }


    return Controller::X3dStickData;
  }      

Controller::gameControllerData Controller::readxBoxController1()
  {
    xBoxControllerData.leftTrigger     = xBoxController1.GetRawAxis(2);
    xBoxControllerData.rightTrigger    = xBoxController1.GetRawAxis(3);
    xBoxControllerData.leftStickYAxis  = xBoxController1.GetRawAxis(1);
    xBoxControllerData.rightStickYAxis = xBoxController1.GetRawAxis(5);
    xBoxControllerData.dPad            = xBoxController1.GetPOV();
    xBoxControllerData.aButton         = xBoxController1.GetRawButton(1);
    xBoxControllerData.bButton         = xBoxController1.GetRawButton(2);
    xBoxControllerData.xButton         = xBoxController1.GetRawButton(3);
    xBoxControllerData.yButton         = xBoxController1.GetRawButton(4);
    xBoxControllerData.leftBumper      = xBoxController1.GetRawButton(5);
    xBoxControllerData.rightBumper     = xBoxController1.GetRawButton(6);
    xBoxControllerData.startButton     = xBoxController1.GetRawButton(8);

    if ((xBoxControllerData.leftStickYAxis < 0.2) and (xBoxControllerData.leftStickYAxis > -0.2))
      {
        xBoxControllerData.leftStickYAxis = 0.0;
      }
       
    if ((xBoxControllerData.rightStickYAxis < 0.2) and (xBoxControllerData.rightStickYAxis > -0.2))
      {
         xBoxControllerData.rightStickYAxis = 0.0;
      }


    return Controller::xBoxControllerData;
  } // end readxBoxController1()


  Controller::gameControllerData Controller::readxBoxController0()
  {
    xBoxControllerData.leftTrigger     = xBoxController0.GetRawAxis(2);
    xBoxControllerData.rightTrigger    = xBoxController0.GetRawAxis(3);
    xBoxControllerData.leftStickYAxis  = xBoxController0.GetRawAxis(1);
    xBoxControllerData.rightStickYAxis = xBoxController0.GetRawAxis(5);
    xBoxControllerData.dPad            = xBoxController0.GetPOV();
    xBoxControllerData.aButton         = xBoxController0.GetRawButton(1);
    xBoxControllerData.bButton         = xBoxController0.GetRawButton(2);
    xBoxControllerData.xButton         = xBoxController0.GetRawButton(3);
    xBoxControllerData.startButton     = xBoxController1.GetRawButton(8);


    if ((xBoxControllerData.leftStickYAxis < 0.2) and (xBoxControllerData.leftStickYAxis > -0.2))
      {
        xBoxControllerData.leftStickYAxis = 0.0;
      }
       
    if ((xBoxControllerData.rightStickYAxis < 0.2) and (xBoxControllerData.rightStickYAxis > -0.2))
      {
         xBoxControllerData.rightStickYAxis = 0.0;
      }


    return Controller::xBoxControllerData;
  } // end readxBoxController0()