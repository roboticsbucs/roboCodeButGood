This is the code for the VEX V5 Competition.
This uses an "event-based paradigm", meaning that motors are only changed when called by an interrupt, which are formed when a button is pressed or a joystick changes its position.
If you just want to set the functions of the buttons, please edit the ControllerWrapper.cpp class
For those interested, this is the control flow:
![IMAGE FAILED TO LOAD](https://github.com/roboticsbucs/roboCodeButGood/blob/main/VEX%20Comp%20Control%20Flow%20Diagram.png)
(trust me, this _is_ the simple solution)
