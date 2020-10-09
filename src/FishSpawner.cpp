#include "FishSpawner.h"

using namespace aquatic;

FishSpawner::FishSpawner()
{
    _spawnInfo = std::vector<FishInfo>();
    fish_count = 0;
}

FishSpawner& FishSpawner::AddFishType(int amount, Color color, int speed, Size size)
{
    return *this;
}

void FishSpawner::Generate(std::vector<Fish>& container)
{
    container.clear();

    int count = 0;

    for (int i = 0; i < _spawnInfo.size(); i++)
    {
        count += _spawnInfo[i].amount;
    }

    container.reserve(fish_count);
}
