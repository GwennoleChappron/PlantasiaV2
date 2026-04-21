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
    balconyView.createHand(5, (float)w, (float)h - 100.0f);
    resourceManager.createTemplateFromRect(renderer, "card", balconyView.getWidth(), balconyView.getHeight(), 255, 255, 255);
    resourceManager.createTemplateFromRect(renderer, "dropZone", 100.0f, 100.0f, 200, 0, 0);
    resourceManager.createTemplateFromImage(renderer, "cardTemplate", "assets/WidgetsTimer.png");
    isRunning = true;
}

Application::~Application(){
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
        dt = (SDL_GetTicks() - lastUpdateTime) / 1000.0f; 
        lastUpdateTime = SDL_GetTicks();
        float mouseX, mouseY;
        inputManager.getMousePosition(mouseX, mouseY);
        balconyView.update(inputManager.getLeftClickState(), mouseX, mouseY, dt);
        update();
        render();
    }
}

void Application::update(){

}

void Application::render() {
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
   balconyView.render(renderer, resourceManager.getTexture("card"), resourceManager.getTexture("dropZone"), resourceManager.getTexture("cardTemplate"));
    SDL_RenderPresent(renderer);
}