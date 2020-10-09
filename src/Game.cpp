#include "game.h"

float Game::deltaTime = 0;

bool Game::Init()
{
	Graphics::SetDimensions(900, 900);

	if (_graphics.Init())
	{
		_running = true;
	}

	_time_old = SDL_GetPerformanceCounter();

	_fish.reserve(30); // Adjust depending on Aquarium size
	_fish.emplace_back(aquatic::Fish(150, aquatic::Color::red, "I'm sorry", 50, 50));
	_fish.emplace_back(aquatic::Fish(150, aquatic::Color::red, "John", 50, 50));

	return _running;
}

void Game::Update()
{
	using namespace aquatic;

	Uint64 time_now = SDL_GetPerformanceCounter();

	deltaTime = (float)((time_now - _time_old) / (float)SDL_GetPerformanceFrequency());

	_time_old = time_now;

	for (Fish& fish : _fish)
	{
		fish.Update();		
	}

	for (int i = 0; i < _fish.size(); i++)
	{
		Fish* fishA = &_fish[i];

		for (int j = i + 1; j < _fish.size(); j++)
		{
			Fish* fishB = &_fish[j];


			/*if (Fish::IsColliding(*fishA, *fishB))
			{
				// Give opportunity for the fish to change their targets
				fishA->OnCollision(*fishB);
				fishB->OnCollision(*fishA);
				
				//Resolve position
				Fish::ResolveCollision(*fishA, *fishB);
			}*/
		}
	}
}


void Game::Input()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			_running = false;
		}
	}
}

void Game::Render()
{
	_graphics.Clear();

	for (aquatic::Fish& fish : _fish)
	{
		_graphics.DrawFish(fish);
	}

	_graphics.Draw();
}

Game::~Game()
{
	_graphics.Close();
}
