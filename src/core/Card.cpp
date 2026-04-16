#include "Card.hpp"

card::card(float x, float y, float width, float height){
    rect = {x, y, width, height};
}

card::~card(){
    std::cout << "Card instance Destroyed." << std::endl;
}

void card::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderRect (renderer, &rect);
}