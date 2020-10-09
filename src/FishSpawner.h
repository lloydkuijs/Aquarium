#pragma once

#include "Fish.h"
#include <iostream>
#include <vector>

class FishSpawner
{
private:
    struct FishInfo
    {
        int amount = 1;
        aquatic::Color color = aquatic::Color::blue;
        int speed = 50;
        aquatic::Size size = { 50, 50 };
        poscol::Vector2 start_position = { 0, 0 };
    };

    int fish_count;
    std::vector<FishInfo> _spawnInfo;

public:
    FishSpawner();
    FishSpawner& AddFishType(int amount, aquatic::Color color, int speed, aquatic::Size size);
    void Generate(std::vector<aquatic::Fish>& container);
};
