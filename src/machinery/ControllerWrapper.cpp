#include "ButtonController.h"
#include "JoystickController.h"
#include "MotorController.h"
#include "Vector2.h"
#include "vex.h"
#include "ControllerWrapper.h"

using namespace std;
using namespace vex;

const vex::controller controllerObj;

/**
 * This is where you put all of the functions relating to user input. 
 * the idea is that you set the movement mode of the motorcontrollers when you press buttons
 * This updates whenever the respective IO device changes state (ie button being pressed/released or joystick changing position)
 * so set the speed for analogue motor control relative to the current position of the joystick's position
 * each event is on its own thread, so there isnt a worry about order of events
 */

MotorController motor_1 = MotorController(MotorListener(vex::motor(1)));
MotorController motor_2 = MotorController(MotorListener(vex::motor(2)));
MotorController motor_3 = MotorController(MotorListener(vex::motor(3)));
MotorController motor_4 = MotorController(MotorListener(vex::motor(4)));
MotorController motor_5 = MotorController(MotorListener(vex::motor(5)));
MotorController motor_6 = MotorController(MotorListener(vex::motor(6)));
MotorController motor_7 = MotorController(MotorListener(vex::motor(7)));
MotorController motor_8 = MotorController(MotorListener(vex::motor(8)));
MotorController motor_9 = MotorController(MotorListener(vex::motor(9)));
MotorController motor_10 = MotorController(MotorListener(vex::motor(10)));
MotorController motor_11 = MotorController(MotorListener(vex::motor(11)));
MotorController motor_12 = MotorController(MotorListener(vex::motor(12)));
MotorController motor_13 = MotorController(MotorListener(vex::motor(13)));
MotorController motor_14 = MotorController(MotorListener(vex::motor(14)));
MotorController motor_15 = MotorController(MotorListener(vex::motor(15)));
MotorController motor_16 = MotorController(MotorListener(vex::motor(16)));
MotorController motor_17 = MotorController(MotorListener(vex::motor(17)));
MotorController motor_18 = MotorController(MotorListener(vex::motor(18)));
MotorController motor_19 = MotorController(MotorListener(vex::motor(19)));
MotorController motor_20 = MotorController(MotorListener(vex::motor(20)));
MotorController motor_21 = MotorController(MotorListener(vex::motor(21)));
MotorController motor_22 = MotorController(MotorListener(vex::motor(22)));

MotorController CONTROLLERS[22] = {motor_1, motor_2, motor_3, motor_4, motor_5, motor_6, motor_7, motor_8, motor_9, motor_10, motor_11, motor_12, motor_13, motor_14, motor_15, motor_16, motor_17, motor_18, motor_19, motor_20, motor_21, motor_22};

const ButtonController BUTTON_A = ButtonController(
    controllerObj.ButtonA,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_B = ButtonController(
    controllerObj.ButtonB,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_X = ButtonController(
    controllerObj.ButtonX,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_Y = ButtonController(
    controllerObj.ButtonY,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_UP = ButtonController(
    controllerObj.ButtonUp,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_DOWN = ButtonController(
    controllerObj.ButtonDown,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_LEFT = ButtonController(
    controllerObj.ButtonRight,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_RIGHT = ButtonController(
    controllerObj.ButtonLeft,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_L1 = ButtonController(
    controllerObj.ButtonL1,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_L2 = ButtonController(
    controllerObj.ButtonL2,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_R1 = ButtonController(
    controllerObj.ButtonR1,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController BUTTON_R2 = ButtonController(
    controllerObj.ButtonR2,
    function<void()>([]() {}),  // onPress
    function<void()>([]() {})); // onRelease
const ButtonController ALL_BUTTONS[12] = {BUTTON_A, BUTTON_B, BUTTON_X, BUTTON_Y, BUTTON_UP, BUTTON_DOWN, BUTTON_LEFT, BUTTON_RIGHT, BUTTON_L1, BUTTON_L2, BUTTON_R1, BUTTON_R2};

const JoystickController LEFT_JOYSTICK = JoystickController(
    JoystickListener(controllerObj.Axis1, controllerObj.Axis2, 0.0),
    function<void(JoystickListener)>([](JoystickListener) {}));
const JoystickController RIGHT_JOYSTICK = JoystickController(
    JoystickListener(controllerObj.Axis3, controllerObj.Axis4, 0.0),
    function<void(JoystickListener)>([](JoystickListener) {}));
const JoystickController ALL_JOYSTICKS[2] = {LEFT_JOYSTICK, RIGHT_JOYSTICK};

void ControllerWrapper::anyButtonEvent()
{
    for (ButtonController button : ALL_BUTTONS)
    {
        if (button.hasBeenPressed())
        {
            button.applyOnPress();
        }
        else if (button.hasBeenReleased())
        {
            button.applyOnRelease();
        }
    }
}

void ControllerWrapper::anyJoystickEvent()
{
    for (JoystickController joystick : ALL_JOYSTICKS)
    {
        if (joystick.getListener().hasChangedPosition())
        {
            joystick.applyOnChange();
        }
    }
}