#pragma once 
#include <vector>
#include <SDL3/SDL.h>

#include "../ui/Card.hpp"

struct BalconyView {
    ~BalconyView();

    void addCard(float x, float y);
    void update(bool isLeftMouseDown, float mouseX, float mouseY);
    void render(SDL_Renderer* renderer, SDL_Texture* cardTemplate);
    inline float getWidth() {
        if (cards.empty()) return 0.0f;
        return cards[0]->getWidth();
    };
    inline float getHeight() {
        if (cards.empty()) return 0.0f;
        return cards[0]->getHeight();
    };
    void createHand (int numCards, float screenX, float screenY);
    private:
    void isHoveringCard(float mouseX, float mouseY);
    void grabCard(bool isLeftMouseDown, float mouseX, float mouseY);
    std::vector<card*> cards;
    card* grabbedCard = nullptr;
    float grabOffsetX = 0.0f;
    float grabOffsetY = 0.0f;
};