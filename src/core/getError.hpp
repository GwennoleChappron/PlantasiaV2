#pragma once
#include <SDL3/SDL.h>
#include <iostream>

inline void checkSDL(int e, const std::string& msg)
{
    if (e < 0) throw std::runtime_error( msg + " failed: " + std::string( SDL_GetError() ));
    std::cout << msg << " passed." << std::endl;
}

inline void checkSDL(bool e, const std::string& msg)
{
    if (!e) throw std::runtime_error( msg + " failed: " + std::string( SDL_GetError() ));
    std::cout << msg << " passed." << std::endl;
}


template <typename T>
inline void checkSDL(T* e, const std::string& msg)
{
    if (!e) throw std::runtime_error( msg + " failed: " + std::string( SDL_GetError() ));
    std::cout << msg << " passed." << std::endl;
}
