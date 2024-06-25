#include "MotorManager.h"

MotorManager::MotorManager(MovementMode _mode, vector<double> _args, bool _needsUpdates)
{
}

void MotorManager::updateMotor(MotorListener _motor)
{
    //TODO: add presets corresponding to all MovementModes
    switch (mode)
    {
    case BRAKING:
        _motor.getMotor().stop(brakeType::brake);
        break;
    case COASTING:
        _motor.getMotor().stop(brakeType::coast);
        break;

    default:
        break;
    }
}

MotorManager::MotorManager()
{
    MotorManager(MovementMode::INACTIVE, vector<double>(), false);
}

MotorManager::~MotorManager()
{
}
