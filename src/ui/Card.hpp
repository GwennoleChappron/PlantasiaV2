#pragma once
#include <SDL3/SDL.h>

struct card{
    card (float x, float y);
    ~card();

    void render(SDL_Renderer* renderer, SDL_Texture* cardTemplate);
    void getSizeCard(SDL_FRect& r){r.w = w; r.h = h;};

    void checkHover(float mouseX, float mouseY);

    private:
    // card immutable properties
    float w = 40.0f; // width card
    float h = 60.0f; // height card
    SDL_FRect rect;

    // card state
    bool isHovered = false;
};