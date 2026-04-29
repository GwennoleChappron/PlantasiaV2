#include "BalconyView.hpp"
#include "../core/PlantManager.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

BalconyView::~BalconyView() {
    for (auto& c : cards) {
        delete c;
    }
    cards.clear();
}

void BalconyView::update(bool isLeftMouseDown, float mouseX, float mouseY, float dt) {
    isHoveringCard(mouseX, mouseY);
    grabCard(isLeftMouseDown, mouseX, mouseY);
    
    dropZone.update(dt);
}

void BalconyView::render(SDL_Renderer* renderer, SDL_Texture* cardTemplate, SDL_Texture* dropZoneTemplate, SDL_Texture* timerTemplate) {
    dropZone.render(renderer, dropZoneTemplate, cardTemplate, timerTemplate);
    for (auto& c : cards) {
        c->render(renderer, cardTemplate);
    }
}

void BalconyView::createHand(const std::vector<PlantProfile*>& plantsToWater, float screenX, float screenY) {
    int numCards = plantsToWater.size();
    
    dropZone.setX(screenX / 2.0f - 50.0f);
    dropZone.setY(screenY / 2.0f - 150.0f);
    
    // On crée une carte visuelle pour chaque plante qui a soif
    for (int i = 0; i < numCards; ++i) {
        cards.push_back(new card(0.0f, 0.0f, plantsToWater[i]));
    }
    
    float spacing = -10.0f;
    float totalWidth = numCards * getWidth() + (numCards - 1) * spacing;
    float startX = (screenX - totalWidth) / 2.0f;
    
    for (size_t i = 0; i < numCards; ++i) {
        cards[i]->setPosition(startX + i * (getWidth() + spacing), screenY);
    }
}

void BalconyView::isHoveringCard(float mouseX, float mouseY) {
    bool topCardHover = false;
    for (int i = cards.size() - 1; i >= 0; --i) {
        if (!topCardHover && cards[i]->containsPoint(mouseX, mouseY)) {
            cards[i]->setHover(true);
            topCardHover = true;
        } else {
            cards[i]->setHover(false);
        }
    }
}

void BalconyView::grabCard(bool isLeftMouseDown, float mouseX, float mouseY) {
    if (grabbedCard) {
        grabbedCard->setPosition(mouseX - grabOffsetX, mouseY - grabOffsetY);
        
        if (isLeftMouseDown == false) {
            if (dropZone.isInside(mouseX, mouseY)) {
                dropZone.addCard(grabbedCard);
                std::erase(cards, grabbedCard);
                grabbedCard = nullptr; 
            } else {
                grabbedCard->setPosition(originalX, originalY);
                grabbedCard = nullptr; 
            }
        }
    } else {
        for (int i = cards.size() - 1; i >= 0; --i) {
            if (cards[i]->containsPoint(mouseX, mouseY) && isLeftMouseDown == true) {
                grabbedCard = cards[i];
                grabOffsetX = mouseX - grabbedCard->getX();
                grabOffsetY = mouseY - grabbedCard->getY();
                originalX = grabbedCard->getX();
                originalY = grabbedCard->getY();
                break;
            }
        }
    }
}