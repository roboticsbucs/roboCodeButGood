#pragma once
#include "vex.h"
#include "JoystickListener.h"

class JoystickController {
    private:
        JoystickListener listener;
        function<void(JoystickListener)> onChange;
    public:
        JoystickController(JoystickListener listener, function<void(JoystickListener)> onChange);
        JoystickListener getListener() { return listener; }
        function<void(JoystickListener)> getOnChangeFunction() { return onChange; }
        void applyOnChange();
};