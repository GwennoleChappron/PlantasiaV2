#include <SDL3/SDL.h>

class ResourceManager {
    public:
    ~ResourceManager();
    void createCardTemplate(SDL_Renderer* r, float w, float h);
    SDL_Texture* getCardTemplate() { return cardTemplate; };

    private:
    SDL_Texture* cardTemplate = nullptr;
    SDL_Renderer* renderer = nullptr;
};