#include "vex.h"
#include <algorithm>
#include "Vector2.h"
#include "JoystickListener.h"
#include <functional>
#include <cmath>
using namespace vex;
using namespace std;

Vector2 JoystickListener::getRawPosition()
{
    return Vector2(xAxis.position() / 100.0, yAxis.position() / 100.0);
}

Vector2 JoystickListener::getAdjustedPosition()
{
    return Vector2(max((this->getRawPosition().getRadius() - deadZoneRadius) / (1 - deadZoneRadius), 0.0),
                   this->getRawPosition().getThetaRadians(), Vector2::DegreeUnit::RADIANS);
}

JoystickListener::JoystickListener(vex::controller::axis xAxis, vex::controller::axis yAxis, double deadZoneRadius) : xAxis(xAxis), yAxis(yAxis), deadZoneRadius(deadZoneRadius) {
    this->lastKnownPosition = Vector2(0,0);
}

bool JoystickListener::hasChangedPosition()
{
    bool output = getRawPosition().equals(getLastRawPosition());
    lastKnownPosition = getRawPosition();
    return output;
}
