#include "game.h"


bool Game::Init()
{
	if (_graphics.Init())
	{
		_running = true;
	}

	_time_old = SDL_GetPerformanceCounter();

	_fish.reserve(4); // Adjust depending on Aquarium size
	_fish.emplace_back(Fish{ {150,150}, 150, Color::blue, "John", {150, 150} });
	_fish.emplace_back(Fish{ {150,150}, 150, Color::blue, "Tijmen", {150, 150} });

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

		const Vector2 current_location = fish.GetLocation();
		const Vector2 target_location = fish.GetTargetLocation();

		std::cout << "X: " << current_location.x << "Y: " << current_location.y << std::endl;
		std::cout << "Target: " << "X: " << target_location.x << "Y: " << target_location.y << std::endl;
	}

	for (int i = 0; i < _fish.size(); i++)
	{
		Fish* fishA = &_fish[i];

		for (int j = i + 1; j < _fish.size(); j++)
		{
			Fish* fishB = &_fish[j];

			if (Fish::IsColliding(*fishA, *fishB))
			{
				fishA->SetColor(Color::red);
				fishB->SetColor(Color::red);
			}
			else
			{
				fishA->SetColor(Color::blue);
				fishB->SetColor(Color::blue);
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
