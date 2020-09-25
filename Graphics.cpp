#include "Graphics.h"

void Graphics::LogSDLError(std::ostream& os, const std::string& msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}

Graphics::~Graphics()
{
	Close();
}

bool Graphics::Init()
{
	bool result = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialise! SDL Error: " << SDL_GetError() << std::endl;
		result = false;
	}
	else
	{
		_window = SDL_CreateWindow("Aquarium", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Graphics::SCREEN_WIDTH, Graphics::SCREEN_WIDTH, SDL_WINDOW_SHOWN);

		if (_window == nullptr)
		{
			std::cout << "There was a problem creating the window: " << SDL_GetError() << std::endl;
			result = false;
		}
		else
		{
			//Get window surface
			_screenSurface = SDL_GetWindowSurface(_window);

			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (_renderer == nullptr) 
			{
				result = false;
			}
		}
	}	

	return result;
}

void Graphics::Close()
{
	SDL_FreeSurface(_screenSurface);
	_screenSurface = nullptr;

	SDL_DestroyWindow(_window);
	_window = nullptr;

	SDL_Quit();
}

void Graphics::DrawFish(const Fish& fish)
{
	auto location = fish.GetLocation();

	SDL_Rect rectangle = { location.x, location.y, 15, 15 }; // the rectangle

	switch (fish.GetColor())
	{
		case Color::blue:
			SDL_SetRenderDrawColor(_renderer, 63, 127, 191, 1);
			break;
		case Color::red:
			SDL_SetRenderDrawColor(_renderer, 191, 63, 63, 1);
			break;
		case Color::green:
			SDL_SetRenderDrawColor(_renderer, 63, 191, 63, 1);
			break;
	}

	SDL_RenderFillRect(_renderer, &rectangle);

}

void Graphics::Clear()
{
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 1);
	SDL_RenderClear(_renderer);
}

void Graphics::Draw()
{
	SDL_RenderPresent(_renderer);

}