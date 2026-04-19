#include <iostream>

#include "Application.hpp"
#include "Card.hpp"
#include "getError.hpp"

Application::Application (const std::string& title, int width, int height, Uint64 flags) {
    
    checkSDL(SDL_Init(SDL_INIT_VIDEO), "initialisation");

    checkSDL(SDL_CreateWindowAndRenderer(title.c_str(), width, height, flags, &window, &renderer), "Window/Renderer");

    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    float cardX = (float)w / 2.0f - 20.0f;
    float cardY = (float)h / 2.0f - 30.0f;
    myCard = new card(cardX, cardY);
    initCardTemplate();    

    isRunning = true;
}

Application::~Application(){
    if (myCard) delete myCard;
    if (cardTemplate) SDL_DestroyTexture(cardTemplate);
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
        switch(event.type){
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            case SDL_EVENT_MOUSE_MOTION:
                myCard->checkHover((float)event.motion.x, (float)event.motion.y);
                break;
        }
    }
}

void Application::update(){

}

void Application::render() {
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    myCard->render(renderer, cardTemplate);
    SDL_RenderPresent(renderer);
}

void Application::initCardTemplate(){
    SDL_FRect rectText = { 0.0f, 0.0f, 0.0f, 0.0f};
    myCard->getSizeCard(rectText);

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