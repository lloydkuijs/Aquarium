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
	/**/

	Game game;

	if (game.Init()) 
	{
		while (game.Running())
		{
			game.Update();
			game.Render();
		}
	}

	return EXIT_SUCCESS;
}