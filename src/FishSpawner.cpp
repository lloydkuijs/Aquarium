#include "FishSpawner.h"
#include "Graphics.h"

using namespace aquatic;

FishSpawner::FishSpawner()
{
    _spawnInfo = std::vector<FishInfo>();
    fish_count = 0;
}

FishSpawner& FishSpawner::AddFishType(FishInfo info)
{
    fish_count += info.amount;

    _spawnInfo.emplace_back(info);

    return *this;
}

void FishSpawner::Generate(std::vector<Fish>& container)
{
    container.clear();
    container.reserve(fish_count);

    poscol::Vector2 start_position = { (float)Graphics::SCREEN_WIDTH / 2, (float)Graphics::SCREEN_HEIGHT / 2 };;

    for (const FishInfo& info : _spawnInfo)
    {
        for (int i = 0; i < info.amount; i++)
        {
            container.emplace_back(aquatic::Fish(info.speed, info.color, info.name, info.size.width, info.size.height, start_position));
        }
    }

}
