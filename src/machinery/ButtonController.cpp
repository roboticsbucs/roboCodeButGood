#include "vex.h"
#include "ButtonController.h"
#include "ControllerWrapper.h"
#include <functional>
using namespace vex;
using namespace std;

/**
 * Precondition: a ControllerButton is controlled by at maximum ONE buttonController
 */
ButtonController::ButtonController(vex::controller::button _buttonId, function<void()> _onPress, function<void()> _onRelease) : buttonId(_buttonId), onPress(_onPress), onRelease(_onRelease)
{
    buttonId.pressed(ControllerWrapper::anyButtonEvent);
}
ButtonController::ButtonController(vex::controller::button _buttonId, function<void()> _onPress) : buttonId(_buttonId), onPress(_onPress)
{
    buttonId.pressed(ControllerWrapper::anyButtonEvent);
}


bool ButtonController::hasBeenPressed()
{
    bool hasBeenPressed = buttonId.pressing() && !wasPressedAsOfLastCheck;
    wasPressedAsOfLastCheck = buttonId.pressing();
    return hasBeenPressed;
}

bool ButtonController::hasBeenReleased()
{
    bool hasBeenReleased = !buttonId.pressing() && wasPressedAsOfLastCheck;
    wasPressedAsOfLastCheck = buttonId.pressing();
    return hasBeenReleased;
}

void ButtonController::setTargetLocation(double _targetLocation)
{
    targetLocation = _targetLocation;
}
