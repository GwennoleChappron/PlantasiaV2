cmake_minimum_required(VERSION 3.20)

# Nom et version de ton projet
project(Plantasia VERSION 1.0 LANGUAGES CXX)

# On impose un standard C++ moderne (C++20 est idéal pour avoir un code propre)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # On désactive les extensions spécifiques aux compilateurs pour rester portable

# ---------------------------------------------------------
# Récupération automatique de SDL3
# ---------------------------------------------------------
include(FetchContent)

message(STATUS "Téléchargement de SDL3 en cours...")
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        main # Tu pourras figer ça sur un tag de version précis plus tard (ex: release-3.x.x)
)

# On construit SDL3 mais on évite de compiler tous ses exemples et tests
set(SDL_TESTS OFF CACHE BOOL "Disable SDL tests" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "Disable SDL examples" FORCE)
FetchContent_MakeAvailable(SDL3)

# ---------------------------------------------------------
# Configuration de ton exécutable
# ---------------------------------------------------------

# Déclaration des fichiers sources de ton projet (pour l'instant, juste main.cpp)
set(SOURCES
    src/main.cpp
    src/core/Application.cpp
    src/core/InputManager.cpp
    src/core/RessourceManager.cpp
    src/ui/Card.cpp
)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier la bibliothèque SDL3 à ton exécutable
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)