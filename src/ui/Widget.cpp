#include "Widget.hpp"
#include <algorithm> // Pour std::clamp

void timerWidget::update(float dt) {
    elapsedTime += dt;
}

void timerWidget::render(SDL_Renderer* renderer, SDL_Texture* timerTexture) {
    if (!timerTexture) return;

    SDL_FRect drawRect = {x, y, sizeTexture, sizeTexture};
    float percent = std::clamp(elapsedTime / duration, 0.0f, 1.0f);
    int currentFrame = (int)(percent * (numFrames - 1));
    SDL_FRect srcRect = { (float)(currentFrame * sizeTexture), 0.0f, sizeTexture, sizeTexture };
    
    SDL_RenderTexture(renderer, timerTexture, &srcRect, &drawRect);
}