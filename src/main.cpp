// Aquarium.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "Graphics.h"
#include "Fish.h"
#include <chrono>
#include <windows.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	int show_console = SW_SHOW;
#if NDEBUG
	show_console = SW_HIDE;
#endif

	HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle, show_console);

	Game game;

	if (game.Init()) 
	{
		while (game.Running())
		{
			game.Update();
			game.Input();
			game.Render();
		}
	}

	return EXIT_SUCCESS;
}