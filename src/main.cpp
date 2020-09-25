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
#if NDEBUG
	HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle, SW_HIDE);
#endif

	Game game;

	if (game.Init()) 
	{

		while (game.Running())
		{
			game.Update();
			game.Input();
			game.Render();
		}

		game.Close();
	}

	return EXIT_SUCCESS;
}