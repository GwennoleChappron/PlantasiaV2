#include "Card.hpp"
#include <iostream>

card::card(float x, float y){
    rect = {x, y, w, h};
}

card::~card(){
    std::cout << "Card instance Destroyed." << std::endl;
}

void card::render(SDL_Renderer* renderer, SDL_Texture* cardTemplate){
    SDL_FRect drawRect = rect;
    if (isHovered) {
        drawRect.w = 1.2f * rect.w;
        drawRect.h = 1.2f * rect.h;
        drawRect.x = rect.x - (drawRect.w - rect.w) / 2.0f;
        drawRect.y = rect.y - (drawRect.h - rect.h) / 2.0f;
    }
    SDL_RenderTexture(renderer, cardTemplate, NULL, &drawRect);
}


void card::checkHover (float mouseX, float mouseY) {
    if (mouseX > rect.x && mouseX < rect.x + rect.w && mouseY > rect.y && mouseY < rect.y + rect.h) {
        isHovered = true;
    } else {
        isHovered = false;
    }
}