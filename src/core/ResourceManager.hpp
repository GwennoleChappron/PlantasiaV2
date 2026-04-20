#pragma once
#include <SDL3/SDL.h>

class ResourceManager {
    public:
    ~ResourceManager();
    void createCardTemplate(SDL_Renderer* r, float w, float h);
    SDL_Texture* getCardTemplate() { return cardTemplate; };

    void createDropZoneTemplate(SDL_Renderer* r, float w, float h);
    SDL_Texture* getDropZoneTemplate() { return dropZoneTemplate; };


    private:
    SDL_Texture* cardTemplate = nullptr;
    SDL_Texture* dropZoneTemplate = nullptr;

    SDL_Renderer* renderer = nullptr;
};