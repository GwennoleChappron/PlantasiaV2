#include "DropZone.hpp"

DropZone::~DropZone() {
    for (auto& c : cards) {
        delete c;
    }
    cards.clear();
}

void DropZone::addCard(card* c) {
    cards.push_back(c);
    timer.setPosition(x + (width / 2.0f) - 16.0f, y + (height / 2.0f) - 16.0f);
}

void DropZone::update(float dt) {
    if (!cards.empty()) {
        timer.update(dt);
        // Si le temps est écoulé, tu pourras supprimer la carte ici !
    }
}

void DropZone::render(SDL_Renderer* renderer, SDL_Texture* dropZoneTemplate, SDL_Texture* cardTemplate, SDL_Texture* timerTemplate) {
    SDL_FRect rect = { x, y, width, height };
    SDL_RenderTexture(renderer, dropZoneTemplate, NULL, &rect);
    for (auto& c : cards) {
        c->render(renderer, cardTemplate);
    }
    if (!cards.empty()) {
        timer.render(renderer, timerTemplate);
    }
}