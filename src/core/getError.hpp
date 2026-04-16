#pragma once
#include <SDL3/SDL.h>
#include <iostream>

void checkSDL(int e, const std::string& msg)
{
    if (e < 0) throw std::runtime_error( msg + " failed: " + std::string( SDL_GetError() ));
    std::cout << msg << " passed." << std::endl;
}

void checkSDL(bool e, const std::string& msg)
{
    if (!e) throw std::runtime_error( msg + " failed: " + std::string( SDL_GetError() ));
    std::cout << msg << " passed." << std::endl;
}


template <typename T>
void checkSDL(T* e, const std::string& msg)
{
    if (!e) throw std::runtime_error( msg + " failed: " + std::string( SDL_GetError() ));
    std::cout << msg << " passed." << std::endl;
}
