#include "PlantManager.hpp"

PlantManager::PlantManager() {
    // 1. On crée les archétypes (Dictionnaire)
    Plant* aloe = new Plant{"Aloe Vera", "Aloe barbadensis", 0};
    Plant* fern = new Plant{"Fougère", "Nephrolepis exaltata", 2};
    plantDatabase.push_back(aloe);
    plantDatabase.push_back(fern);

    // 2. On crée le balcon du joueur (Instances)
    // Bébou a soif (true), Soiffarde a soif (true), mais Chill va bien (false)
    plantsLibrary.push_back(new PlantProfile{"Bébou", true, 10.0f, aloe});
    plantsLibrary.push_back(new PlantProfile{"Soiffarde", true, 5.0f, fern});
    plantsLibrary.push_back(new PlantProfile{"Chill", false, 20.0f, aloe});
}

PlantManager::~PlantManager() {
    // On nettoie la RAM à la fermeture du jeu
    for (auto p : plantsLibrary) delete p;
    for (auto p : plantDatabase) delete p;
}

std::vector<PlantProfile*> PlantManager::needingAttention() {
    std::vector<PlantProfile*> result;
    for (auto plant : plantsLibrary) {
        if (plant->needsAttention) {
            result.push_back(plant); // On renvoie le pointeur !
        }
    }
    return result;
}