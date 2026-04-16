#include <iostream>
#include <SDL3/SDL.h>
#include "core/Application.hpp"

int main(int argc, char* argv[]) {
    try {
        Application Plantasia("Plantasia", 800, 600, 0);
        Plantasia.run();

    } catch (const std::exception& e) {
        std::cerr << "ERREUR : " << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}
