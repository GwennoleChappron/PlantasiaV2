#include "DropZone.hpp"

DropZone::~DropZone() {
    for (auto& c : cards) {
        delete c;
    }
    cards.clear();
}

void DropZone::addCard(card* c) {
    cards.push_back(c);
}

void DropZone::render(SDL_Renderer* renderer, SDL_Texture* dropZoneTemplate, SDL_Texture* cardTemplate) {
    SDL_FRect rect = { x, y, width, height };
    SDL_RenderTexture(renderer, dropZoneTemplate, NULL, &rect);
    for (auto& c : cards) {
        c->render(renderer, cardTemplate);
    }
}