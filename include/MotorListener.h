#pragma once
#include "vex.h"

using namespace vex;
using namespace std;

class MotorListener{
    private:
        motor motorId;
        double lastKnownLocation;
    public:
        MotorListener(motor _motorId) : motorId(_motorId){}
        double getPositionDegrees() { return motorId.position(deg); }
        rotation getVelocityPct() { return motorId.velocity(pct); }
        int getMotorPort() { return motorId.index(); }
        vex::motor getMotor() { return motorId; }
        double getTemperatureDegreesFahrenheit() { return motorId.temperature(fahrenheit); }
        double getTemperatureDegreesCelsius() {return motorId.temperature(celsius); }
};