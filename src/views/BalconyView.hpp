#pragma once 
#include <vector>
#include <SDL3/SDL.h>

#include "../ui/Card.hpp"
#include "../ui/DropZone.hpp"

struct BalconyView {
    ~BalconyView();

    void addCard(float x, float y);
    
    // Ajout du paramètre dt
    void update(bool isLeftMouseDown, float mouseX, float mouseY, float dt);
    
    // Ajout du paramètre timerTemplate
    void render(SDL_Renderer* renderer, SDL_Texture* cardTemplate, SDL_Texture* dropZoneTemplate, SDL_Texture* timerTemplate);
    
    inline float getWidth() {
        if (cards.empty()) return 0.0f;
        return cards[0]->getWidth();
    };
    inline float getHeight() {
        if (cards.empty()) return 0.0f;
        return cards[0]->getHeight();
    };
    
    void createHand(int numCards, float screenX, float screenY);

private:
    DropZone dropZone;
    void isHoveringCard(float mouseX, float mouseY);
    void grabCard(bool isLeftMouseDown, float mouseX, float mouseY);
    
    std::vector<card*> cards;
    card* grabbedCard = nullptr;
    
    float grabOffsetX = 0.0f;
    float grabOffsetY = 0.0f;
    float originalX = 0.0f;
    float originalY = 0.0f;
};