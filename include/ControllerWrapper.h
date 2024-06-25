#pragma once
#include "vex.h"

using namespace vex;
using namespace std;

class ControllerWrapper
{
public:
    static void anyButtonEvent();
    static void anyJoystickEvent();
};
