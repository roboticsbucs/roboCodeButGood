#pragma once
#include "vex.h"
#include "MotorListener.h"
#include "MovementMode.h"
#include "MotorManager.h"
#include <functional>

using namespace std;
using namespace vex;

class MotorController
{
private:
    const MotorListener listener;
    MotorManager manager;

public:
    MotorController(MotorListener _listener);
    void updateMotor() { manager.updateMotor(listener); }
    void setManager(MotorManager newManager) { this->manager = newManager; }
};