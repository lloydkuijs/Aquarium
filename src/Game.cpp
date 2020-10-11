#include "game.h"
#include "FishSpawner.h"

float Game::deltaTime = 0;

bool Game::Init()
{
	//Graphics::SetDimensions(900, 1200);

	if (_graphics.Init())
	{
		_running = true;
	}

	_time_old = SDL_GetPerformanceCounter();

	FishSpawner spawner;
	spawner
		.AddFishType(FishInfo{ 65, aquatic::Color::red, 70, {35, 35}, "Medium fish" })
		.AddFishType(FishInfo{ 75, aquatic::Color::blue, 120, {15, 15}, "Fast fish" })
		.AddFishType(FishInfo{ 50, aquatic::Color::green, 120, {60, 60}, "Big fish" })
		.Generate(_fish);

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
		poscol::RectangleCollider* colliderA = &_fish[i].collider;

		for (int j = i + 1; j < _fish.size(); j++)
		{
			poscol::RectangleCollider* colliderB = &_fish[j].collider;

			if (colliderA->IsColliding(*colliderB))
			{
				Fish* fishA = &_fish[i];
				Fish* fishB = &_fish[j];

				fishA->OnCollision(*fishB);
				fishB->OnCollision(*fishA);

				colliderA->Collide(*colliderB);
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
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				_running = false;
			}
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
