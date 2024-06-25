#include "JoystickController.h"
// #include "FunctionWrapper.h"
#include <iostream>
#include <functional>

JoystickController::JoystickController(JoystickListener listener, function<void(JoystickListener)> onChange) : listener(listener), onChange(onChange)
{
}
void JoystickController::applyOnChange(){
    onChange.operator()(listener);
}
