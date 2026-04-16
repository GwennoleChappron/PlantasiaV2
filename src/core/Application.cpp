#include <iostream>

#include "Application.hpp"
#include "getError.hpp"

Application::Application (const std::string& title, int width, int height, Uint64 flags) {
    
    checkSDL(SDL_Init(SDL_INIT_VIDEO), "initialisation");

    checkSDL(SDL_CreateWindowAndRenderer(title.c_str(), width, height, flags, &window, &renderer), "Window/Renderer");

    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    card = {
        (float) w / 2.0f - 20.0f,
        (float) h / 2.0f - 30.0f,
        40.0f,
        60.0f,
    };
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
        handleEvent();
        update();
        render();
    }
}

void Application::handleEvent(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT) {isRunning = false;}
    }
}

void Application::update(){

}

void Application::render() {
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Draw card
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &card);

    SDL_RenderPresent(renderer);
}