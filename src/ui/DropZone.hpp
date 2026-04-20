#pragma once
#include <SDL3/SDL.h>
#include "Card.hpp"
#include <vector>


class DropZone {
public:
    DropZone(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
    ~DropZone();

    bool isInside(float mouseX, float mouseY) {
        return mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height;
    }
    void addCard(card* c);
    void render(SDL_Renderer* renderer, SDL_Texture* dropZoneTemplate, SDL_Texture* cardTemplate);
    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
    float getX() { return x; }
    float getY() { return y; }
    float getWidth() { return width; }
    float getHeight() { return height; }
private:
    float x, y, width = 100, height = 100;
    std::vector<card*> cards;
};