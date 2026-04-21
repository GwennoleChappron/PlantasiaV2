#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <map>
#include <string>

class ResourceManager {
public:
    ~ResourceManager();

    void createTemplateFromRect(SDL_Renderer* r, const std::string& id, float w, float h, Uint8 colorR, Uint8 colorG, Uint8 colorB);
    void createTemplateFromImage(SDL_Renderer* r, const std::string& id, const std::string& imagePath, float x = 0.0f, float y = 0.0f, float w = 0.0f, float h = 0.0f);

    SDL_Texture* getTexture(const std::string& id);

private:
    std::map<std::string, SDL_Texture*> textures;
    SDL_Renderer* renderer = nullptr;
};