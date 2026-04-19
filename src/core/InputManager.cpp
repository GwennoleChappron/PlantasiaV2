#include "InputManager.hpp"

bool InputManager::update() {
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_EVENT_QUIT:
                quitRequested = true;
                break;
            case SDL_EVENT_MOUSE_MOTION:
                mouseX = (float)event.motion.x;
                mouseY = (float)event.motion.y;
                break;
        }
    }
    return quitRequested; // Plus élégant que if(quitRequested) return true;
}