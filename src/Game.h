#pragma once

#include "Graphics.h"
#include "Fish.h"
#include <list>


/// <summary>
/// Main class of the application, takes care of interaction, model updating and communicates with the graphics class
/// </summary>
class Game
{

private:
	Graphics _graphics;
	bool _running;
	Uint64 _time_old;
	std::vector<Fish> _fish = { Fish { {50,50}, 90, Color::blue, "John", {750, 600}} };

public:
	bool Init();
	void Update();
	void Input();
	void Close();
	void Render();
	inline bool Running() { return _running; };
};

