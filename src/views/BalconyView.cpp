#include "BalconyView.hpp"
#include "../core/InputManager.hpp"

BalconyView::~BalconyView() {
    for (auto& c : cards) {
        delete c;
    }
    cards.clear();
}

void BalconyView::addCard(float x, float y) {
    cards.push_back(new card(x, y));
}

void BalconyView::update(bool isLeftMouseDown, float mouseX, float mouseY) {
    isHoveringCard(mouseX, mouseY);

    grabCard(isLeftMouseDown, mouseX, mouseY);
}

void BalconyView::render(SDL_Renderer* renderer, SDL_Texture* cardTemplate) {
    for (auto& c : cards) {
        c->render(renderer, cardTemplate);
    }
}

void BalconyView::createHand(int numCards, float screenX, float screenY) {
    for (int i = 0; i < numCards; ++i) {
        addCard(0.0f, 0.0f); // initial position will be set later
    }
    float spacing = -10.0f; // spacing between cards
    float totalWidth = numCards * getWidth() + (numCards - 1) * spacing;
    float startX = (screenX - totalWidth) / 2.0f; // center the hand on screenX
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
            grabbedCard = nullptr;
        }
    } else {
        for (int i = cards.size() - 1; i >= 0; --i) {
            if (cards[i]->containsPoint(mouseX, mouseY) && isLeftMouseDown == true) {
                grabbedCard = cards[i];
                grabOffsetX = mouseX - grabbedCard->getPositionX();
                grabOffsetY = mouseY - grabbedCard->getPositionY();
                break;
            }
        }
    }
    
}