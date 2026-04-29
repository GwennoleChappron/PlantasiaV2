#pragma once
#include <vector>
#include <string>
#include "../data/PlantProfile.hpp"

class PlantManager {
public:
    PlantManager();
    ~PlantManager();

    std::vector<PlantProfile*> needingAttention();
    PlantProfile* getPlantByName(const std::string& name);

private:
    std::vector<Plant*> plantDatabase;       
    std::vector<PlantProfile*> plantsLibrary;
};