#pragma once
#include "vex.h"
#include <algorithm>
#include "Vector2.h"
#include <functional>
using namespace vex;
using namespace std;

class JoystickListener
{
private:
    /* data */
    const vex::controller::axis xAxis;
    const vex::controller::axis yAxis;
    const double deadZoneRadius;
    Vector2 lastKnownPosition;
    void setLastKnownPosition(Vector2 _lastKnownPosition) { lastKnownPosition = _lastKnownPosition; }
public:
    Vector2 getRawPosition();

    Vector2 getLastRawPosition() { return lastKnownPosition; }

    Vector2 getAdjustedPosition();

    JoystickListener(vex::controller::axis xAxis, vex::controller::axis yAxis, double deadZoneRadiusPct);

    bool hasChangedPosition();

    controller::axis getXAxis() { return xAxis; }
    controller::axis getYAxis() { return yAxis; }

};