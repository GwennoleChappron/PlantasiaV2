cmake_minimum_required(VERSION 3.20)

# Nom et version de ton projet
project(Plantasia VERSION 1.0 LANGUAGES CXX)

# On impose un standard C++ moderne (C++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------------------------------------
# Récupération des bibliothèques via vcpkg
# ---------------------------------------------------------
# vcpkg a déjà fait le travail lourd. On dit juste à CMake de trouver les fichiers.
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

# ---------------------------------------------------------
# Configuration de ton exécutable
# ---------------------------------------------------------

# Déclaration de tous les fichiers sources de ton projet
set(SOURCES
    src/main.cpp
    src/core/Application.cpp
    src/core/InputManager.cpp
    src/core/ResourceManager.cpp
    src/core/PlantManager.cpp
    src/views/BalconyView.cpp
    src/ui/Card.cpp
    src/ui/DropZone.cpp
    src/ui/Widget.cpp
)

# Création de l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier les bibliothèques pré-compilées par vcpkg à ton exécutable
target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3 
    SDL3_image::SDL3_image
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
)