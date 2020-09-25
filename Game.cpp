#include "game.h"


bool Game::Init()
{
	if (_graphics.Init())
	{
		_running = true;
	}

	_time_old = SDL_GetPerformanceCounter();

	return _running;
}

void Game::Update()
{
	float deltaTime = 0;

	Uint64 time_now = SDL_GetPerformanceCounter();

	deltaTime = (float)((time_now - _time_old) / (float)SDL_GetPerformanceFrequency());

	_time_old = time_now;

	for (Fish& fish : _fish)
	{
		if (fish.IsAtTarget())
		{
			fish.PickRandomTarget(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
		}

		fish.Update(deltaTime);

		std::cout << "X: " << fish.GetLocation().x << "Y: " << fish.GetLocation().y << std::endl;
		std::cout << "Target: " << "X: " << fish.GetTargetLocation().x << "Y: " << fish.GetTargetLocation().y << std::endl;
	}

}

void Game::Render()
{
	_graphics.Clear();

	for (Fish& fish : _fish)
	{
		_graphics.DrawFish(fish);
	}

	_graphics.Draw();
}
