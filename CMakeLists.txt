cmake_minimum_required(VERSION 3.20)

project(Plantasia VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------
# Récupération de SDL3 et SDL3_image
# ---------------------------------------------------------
include(FetchContent)

# Configuration globale pour les dépendances
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_IMAGE_SAMPLES OFF CACHE BOOL "" FORCE) # Désactive les démos de SDL_image
set(SDL_IMAGE_TESTS OFF CACHE BOOL "" FORCE)   # Désactive les tests de SDL_image
set(SDLIMAGE_AVIF OFF CACHE BOOL "Disable AVIF support" FORCE)
set(SDLIMAGE_WEBP OFF CACHE BOOL "Disable WEBP support" FORCE)
set(SDLIMAGE_TIFF OFF CACHE BOOL "Disable TIFF support" FORCE)
set(SDLIMAGE_JXL OFF CACHE BOOL "Disable JXL support" FORCE)

# SDL3
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main 
)

# SDL3_image
FetchContent_Declare(
    SDL3_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG main
)

# On rend les deux disponibles
FetchContent_MakeAvailable(SDL3 SDL3_image)

# ---------------------------------------------------------
# Configuration de l'exécutable
# ---------------------------------------------------------

set(SOURCES
    src/main.cpp
    src/core/Application.cpp
    src/core/InputManager.cpp
    src/core/ResourceManager.cpp
    src/views/BalconyView.cpp
    src/ui/Card.cpp
    src/ui/DropZone.cpp
    src/ui/Widget.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# /!\ AJOUT ICI : On lie SDL3 ET SDL3_image
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3 
    SDL3_image::SDL3_image
)

# Copier les assets dans le dossier de build (très utile sur Windows)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)