#pragma once
#include <SDL3/SDL.h>

struct timerWidget {
    timerWidget() : elapsedTime(0.0f) {}

    void update(float dt);
    void render(SDL_Renderer* renderer, SDL_Texture* timerTexture);
    void setPosition(float newX, float newY) { x = newX; y = newY; }
    void setDuration(float newDuration) { duration = newDuration; }
    bool isFinished() const { return elapsedTime >= duration; }

private:
    float x = 0.0f, y = 0.0f;
    float duration = 10.0f; 
    float elapsedTime = 0.0f;
    int numFrames = 10;
    float sizeTexture = 32.0f;
};