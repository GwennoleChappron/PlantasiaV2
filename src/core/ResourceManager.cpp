#include "ResourceManager.hpp"
#include "getError.hpp"

ResourceManager::~ResourceManager() {
    // On boucle sur toute la map pour détruire chaque texture
    for (auto& pair : textures) {
        if (pair.second) {
            SDL_DestroyTexture(pair.second);
        }
    }
    textures.clear();
}

void ResourceManager::createTemplateFromRect(SDL_Renderer* r, const std::string& id, float w, float h, Uint8 colorR, Uint8 colorG, Uint8 colorB) {
    renderer = r;
    if (textures.find(id) != textures.end()) {
        return; 
    }
    SDL_FRect rectText = { 0.0f, 0.0f, w, h };
    SDL_Texture* newTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, rectText.w, rectText.h);

    checkSDL(newTexture, "Texture");
    
    SDL_SetRenderTarget(renderer, newTexture);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rectText);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderRect(renderer, &rectText);
    
    SDL_SetRenderTarget(renderer, NULL);
    textures[id] = newTexture;
}

void ResourceManager::createTemplateFromImage(SDL_Renderer* r, const std::string& id, const std::string& imagePath, float x, float y, float w, float h) {
    renderer = r;
    if (textures.find(id) != textures.end()) {
        return; 
    }
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, imagePath.c_str());
    checkSDL(newTexture, "Load Texture from Image");
    textures[id] = newTexture;
}

SDL_Texture* ResourceManager::getTexture(const std::string& id) {
    if (textures.find(id) != textures.end()) {
        return textures[id];
    }
    return nullptr;
}