#include "game.h"


bool Game::Init()
{
	Graphics::SetDimensions(900, 900);

	if (_graphics.Init())
	{
		_running = true;
	}

	_time_old = SDL_GetPerformanceCounter();

	_fish.reserve(30); // Adjust depending on Aquarium size
	_fish.emplace_back(Fish(150, Color::red, "I'm sorry", Size{ 50, 50 }, { 0, 0 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 200, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 300, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 400, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 50, 50 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 15, 15 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 15, 15 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 15, 15 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 15, 15 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 5, 5 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 15, 15 }, { 500, 150 }));
	_fish.emplace_back(Fish(150, Color::red, "John", Size{ 15, 15 }, { 500, 150 }));

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
		fish.Update(deltaTime);		
	}

	for (int i = 0; i < _fish.size(); i++)
	{
		Fish* fishA = &_fish[i];

		for (int j = i + 1; j < _fish.size(); j++)
		{
			Fish* fishB = &_fish[j];

			if (Fish::IsColliding(*fishA, *fishB))
			{
				// Give opportunity for the fish to change their targets
				fishA->OnCollision(*fishB);
				fishB->OnCollision(*fishA);
				
				//Resolve position
				Fish::ResolveCollision(*fishA, *fishB);
			}
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

	for (Fish& fish : _fish)
	{
		_graphics.DrawFish(fish);
	}

	_graphics.Draw();
}

Game::~Game()
{
	_graphics.Close();
}
