#pragma once

#include <SDL.h>
#include <iostream>
#include "Fish.h"

class Graphics
{
private:
	SDL_Window* _window;
	SDL_Surface* _screenSurface;
	SDL_Renderer* _renderer;

	void LogSDLError(std::ostream& os, const std::string& msg);

public:
	static const int SCREEN_WIDTH = 1200;
	static const int SCREEN_HEIGHT = 800;

	~Graphics();

	//Starts up SDL and creates window
	bool Init();

	//Frees media and shuts down SDL
	void Close();

	void DrawFish(const Fish& fish);

	void Clear();

	void Draw();
};

