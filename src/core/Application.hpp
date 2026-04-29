#pragma once
#include <SDL3/SDL.h>
#include <string>
#include "InputManager.hpp"
#include "ResourceManager.hpp"
#include "../views/BalconyView.hpp"
#include "PlantManager.hpp"

struct card;

struct Application {

    Application (const std::string& title, int width, int height, Uint64 flags);
    ~Application();

    Application(Application&) = delete;
    Application& operator = (const Application&) = delete;

    void run();

    private:
    PlantManager plantManager;
    InputManager inputManager;
    ResourceManager resourceManager;
    BalconyView balconyView;
    void update ();
    void render ();

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;
    float dt = 0.0f, lastUpdateTime = 0.0f;
};