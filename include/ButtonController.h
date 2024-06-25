#pragma once
#include "vex.h"
#include "MovementMode.h"
#include <functional>
using namespace vex;
using namespace std;
/**
 * Precondition: a ControllerButton is controlled by at maximum ONE buttonController
 */
class ButtonController
{
private:
    const vex::controller::button buttonId;
    function<void()> onPress;
    function<void()> onRelease;
    bool wasPressedAsOfLastCheck = false;
    MovementMode movementMode;
    double targetLocation;
    double movementSpeed;
public:
    ButtonController(vex::controller::button buttonId, function<void()> onPress, function<void()> onRelease);
    ButtonController(vex::controller::button buttonId, function<void()> onPress);
    bool hasBeenPressed();
    bool hasBeenReleased();
    void applyOnPress() {onPress.operator()();}
    void applyOnRelease() {onRelease.operator()();}
    void setTargetLocation(double targetLocation);
};