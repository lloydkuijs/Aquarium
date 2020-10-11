#pragma once

#include "Fish.h"
#include <iostream>
#include <vector>

struct FishInfo
{
    int amount = 1;
    aquatic::Color color = aquatic::Color::blue;
    int speed = 50;
    aquatic::Size size = { 50, 50 };
    std::string name = "";
};

class FishSpawner
{
private:
    int fish_count;
    std::vector<FishInfo> _spawnInfo;

public:
    FishSpawner();
    FishSpawner& AddFishType(FishInfo info);
    void Generate(std::vector<aquatic::Fish>& container);

};
