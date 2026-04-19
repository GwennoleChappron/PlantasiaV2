#pragma once
#include <SDL3/SDL.h>

class InputManager {
public:
    bool update();
    void getMousePosition(float& x, float& y) const {
        x = mouseX;
        y = mouseY;
    }
    bool getLeftClickState() const { return isLeftMouseDown; }
private:
    bool quitRequested = false;
    bool isLeftMouseDown = false;
    float mouseX = 0.0f;
    float mouseY = 0.0f;
};