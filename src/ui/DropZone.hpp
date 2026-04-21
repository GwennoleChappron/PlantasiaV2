#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include "Card.hpp"
#include "Widget.hpp" // Ton nouveau fichier pour le timer

struct DropZone {
    ~DropZone();

    void addCard(card* c);
    void update(float dt); // Nouveau !
    void render(SDL_Renderer* renderer, SDL_Texture* dropZoneTemplate, SDL_Texture* cardTemplate, SDL_Texture* timerTemplate);

    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }
    
    // Fonction mathématique pour savoir si la souris est dans la zone
    bool isInside(float mouseX, float mouseY) {
        return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
    }

private:
    float x = 0.0f;
    float y = 0.0f;
    float width = 100.0f; // La taille de ta zone de dépôt
    float height = 100.0f;
    
    std::vector<card*> cards;
    std::vector<timerWidget> timers; // Les timers sont possédés par la zone
};