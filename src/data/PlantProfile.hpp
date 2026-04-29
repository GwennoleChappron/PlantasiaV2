#pragma once
#include <string>

struct Plant {
    std::string commonName;
    std::string scientificName;
    int waterNeeds = 0; // 0: low, 1: medium, 2: high
};

struct PlantProfile {
    public:
    std::string nickName;
    bool needsAttention = false;
    float age = 0.0f; // in days
    Plant* plantType = nullptr; // Pointer to the plant type this profile represents
};