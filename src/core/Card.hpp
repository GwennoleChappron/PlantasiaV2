#pragma once
#include <SDL3/SDL.h>

struct card{
    card (float x, float y, float width, float height);
    ~card();

    void render(SDL_Renderer* renderer);

    private:
    SDL_FRect rect;
};