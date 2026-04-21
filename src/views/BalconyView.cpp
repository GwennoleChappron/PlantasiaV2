#include "BalconyView.hpp"
#include <iostream>
#include <vector>
#include <algorithm> // Requis pour std::erase en C++20

BalconyView::~BalconyView() {
    for (auto& c : cards) {
        delete c;
    }
    cards.clear();
}

void BalconyView::addCard(float x, float y) {
    cards.push_back(new card(x, y));
}

void BalconyView::update(bool isLeftMouseDown, float mouseX, float mouseY, float dt) {
    isHoveringCard(mouseX, mouseY);
    grabCard(isLeftMouseDown, mouseX, mouseY);
    
    // On fait avancer le temps de la DropZone (et donc de son timer)
    dropZone.update(dt);
}

void BalconyView::render(SDL_Renderer* renderer, SDL_Texture* cardTemplate, SDL_Texture* dropZoneTemplate, SDL_Texture* timerTemplate) {
    // La dropZone a besoin des 3 textures pour se dessiner, dessiner sa carte, et dessiner son timer
    dropZone.render(renderer, dropZoneTemplate, cardTemplate, timerTemplate);
    
    // Ensuite, on dessine les cartes de notre main par-dessus
    for (auto& c : cards) {
        c->render(renderer, cardTemplate);
    }
}

void BalconyView::createHand(int numCards, float screenX, float screenY) {
    dropZone.setX(screenX / 2.0f - 50.0f);
    dropZone.setY(screenY / 2.0f - 150.0f); // J'ai remonté la dropZone pour éviter qu'elle ne chevauche tes cartes en main !
    
    for (int i = 0; i < numCards; ++i) {
        addCard(0.0f, 0.0f);
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
            // L'utilisateur lâche le clic
            if (dropZone.isInside(mouseX, mouseY)) {
                dropZone.addCard(grabbedCard);
                std::erase(cards, grabbedCard);
                grabbedCard = nullptr; // CORRECTION : On lâche la carte !
            } else {
                grabbedCard->setPosition(originalX, originalY);
                grabbedCard = nullptr; // CORRECTION : On lâche la carte !
            }
        }
    } else {
        // L'utilisateur cherche à attraper une carte
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