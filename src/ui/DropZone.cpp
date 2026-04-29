#include "DropZone.hpp"
#include "../data/PlantProfile.hpp"
#include <algorithm>

DropZone::~DropZone() {
    for (auto& c : cards) {
        delete c;
    }
    cards.clear();
}

void DropZone::addCard(card* c) {
    cards.push_back(c);
    timers.emplace_back();
    timers.back().setPosition(c->getX()+c->getWidth()/2.0f-16.0f, c->getY()+c->getHeight()/2.0f-16.0f); // Positionne le timer au centre de la carte
}

void DropZone::update(float dt) {
    std::erase_if(timers, [this, dt](auto& timer) {
        timer.update(dt);
        
        if (timer.isFinished()) {
            if (!this->cards.empty()) {
                card* c = this->cards.front();
                c->profile->needsAttention = false;
                delete c;
                this->cards.erase(this->cards.begin());
                
            }
            return true; 
        }
        return false; 
    });
}

void DropZone::render(SDL_Renderer* renderer, SDL_Texture* dropZoneTemplate, SDL_Texture* cardTemplate, SDL_Texture* timerTemplate) {
    SDL_FRect rect = { x, y, width, height };
    SDL_RenderTexture(renderer, dropZoneTemplate, NULL, &rect);
    for (auto& c : cards) {
        c->render(renderer, cardTemplate);
    }
    if (!cards.empty()) {
        for (auto& timer : timers) {
            timer.render(renderer, timerTemplate);
        }
    }
}