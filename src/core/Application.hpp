#pragma once
#include <SDL3/SDL.h>
#include <string>

struct card;

struct Application {

    Application (const std::string& title, int width, int height, Uint64 flags);
    ~Application();

    Application(Application&) = delete;
    Application& operator = (const Application&) = delete;

    void run();

    private:
    void handleEvent ();
    void update ();
    void render ();

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = false;
    card* myCard = nullptr;

    SDL_Texture* cardTemplate = nullptr;
    void initCardTemplate();
};