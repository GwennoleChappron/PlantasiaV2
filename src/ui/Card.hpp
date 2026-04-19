#pragma once
#include <SDL3/SDL.h>

struct card{
    card (float x, float y);
    ~card();

    void render(SDL_Renderer* renderer, SDL_Texture* cardTemplate);
    float getWidth(){return w;};
    float getHeight(){return h;};

    void checkHover(float mouseX, float mouseY);

    private:
    // card immutable properties
    float w = 40.0f; // width card
    float h = 60.0f; // height card
    SDL_FRect rect;

    // card state
    bool isHovered = false;
};