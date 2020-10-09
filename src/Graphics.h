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
	static int SCREEN_WIDTH, SCREEN_HEIGHT;
	~Graphics();

	static void SetDimensions(int screen_height, int screen_width);

	//Starts up SDL and creates window
	bool Init();

	//Frees media and shuts down SDL
	void Close();

	void DrawFish(const aquatic::Fish& fish);

	void Clear();

	void Draw();
};

