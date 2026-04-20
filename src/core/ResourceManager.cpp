#include <SDL3/SDL.h>
#include "ResourceManager.hpp"
#include "getError.hpp"

ResourceManager::~ResourceManager() {
    if (cardTemplate) SDL_DestroyTexture(cardTemplate);
    if (dropZoneTemplate) SDL_DestroyTexture(dropZoneTemplate);
}

void ResourceManager::createCardTemplate(SDL_Renderer* r, float w, float h) {
    renderer = r;
    SDL_FRect rectText = { 0.0f, 0.0f, w, h };
    cardTemplate = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rectText.w, rectText.h);

    checkSDL(cardTemplate, "Texture");
    SDL_SetRenderTarget(renderer, cardTemplate);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rectText);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderRect(renderer, &rectText);
    SDL_SetRenderTarget(renderer, NULL);
}

void ResourceManager::createDropZoneTemplate(SDL_Renderer* r, float w, float h) {
    renderer = r;
    SDL_FRect rectText = { 0.0f, 0.0f, w, h };
    dropZoneTemplate = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rectText.w, rectText.h);

    checkSDL(dropZoneTemplate, "Texture");
    SDL_SetRenderTarget(renderer, dropZoneTemplate);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rectText);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderRect(renderer, &rectText);
    SDL_SetRenderTarget(renderer, NULL);
}