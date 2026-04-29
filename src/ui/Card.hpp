#pragma once
#include <SDL3/SDL.h>

struct PlantProfile;

struct card{
    card (float x, float y, PlantProfile* profile);
    ~card();

    void render(SDL_Renderer* renderer, SDL_Texture* cardTemplate);
    float getWidth(){return w;};
    float getHeight(){return h;};

    bool containsPoint(float mouseX, float mouseY);
    void setPosition(float x, float y);
    void setHover(bool state) { isHovered = state; };
    float getX() { return rect.x; };
    float getY() { return rect.y; };

    PlantProfile* profile = nullptr; // Pointer to the plant this card represents

    private:
    // card immutable properties
    float w = 40.0f; // width card
    float h = 60.0f; // height card
    SDL_FRect rect;

    // card state
    bool isHovered = false;

    // Card specific properties
    
};