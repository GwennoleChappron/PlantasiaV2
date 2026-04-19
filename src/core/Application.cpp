#include <iostream>

#include "Application.hpp"
#include "InputManager.hpp"
#include "ResourceManager.hpp"
#include "../ui/Card.hpp"
#include "getError.hpp"


Application::Application (const std::string& title, int width, int height, Uint64 flags) {
    
    checkSDL(SDL_Init(SDL_INIT_VIDEO), "initialisation");

    checkSDL(SDL_CreateWindowAndRenderer(title.c_str(), width, height, flags, &window, &renderer), "Window/Renderer");

    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    float cardX = (float)w / 2.0f - 20.0f;
    float cardY = (float)h / 2.0f - 30.0f;
    myCard = new card(cardX, cardY);  
    resourceManager.createCardTemplate(renderer, myCard->getWidth(), myCard->getHeight());
    isRunning = true;
}

Application::~Application(){
    if (myCard) delete myCard;
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Close SDL instance." << std::endl;
}

void Application::run(){
    while(isRunning){
        if (inputManager.update() == true) {
            isRunning = false;
        }
        float mouseX, mouseY;
        inputManager.getMousePosition(mouseX, mouseY);
        myCard->checkHover(mouseX, mouseY);
        update();
        render();
    }
}

void Application::update(){

}

void Application::render() {
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    myCard->render(renderer, resourceManager.getCardTemplate());
    SDL_RenderPresent(renderer);
}