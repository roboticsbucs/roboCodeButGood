#pragma once
#include "vex.h"
#include <vector>
#include "MovementMode.h"
#include "MotorListener.h"
#include <ctime>

using namespace vex;
using namespace std;

class MotorManager
{
private:
    MovementMode mode;
    vector<double> args;
    bool needsUpdates;
    MotorManager(MovementMode _mode, vector<double> _args, bool _needsUpdates);
public:
    void updateMotor(MotorListener _motor);
    MotorManager();
    void deactivate();
    // presets
    static const MotorManager braker();
    static const MotorManager coaster();
    static MotorManager constantMover(double speedPct);
    static MotorManager constantMover(double speedPct, double secondsBeforeDeacivation);
    static MotorManager holder();
    static MotorManager pidMover();
    ~MotorManager();
};
