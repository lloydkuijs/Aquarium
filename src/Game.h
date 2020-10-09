#pragma once

#include "Graphics.h"
#include "Fish.h"
#include <vector>


/// <summary>
/// Main class of the application, takes care of interaction, model updating and communicates with the graphics class
/// </summary>
class Game
{

private:
	Graphics _graphics;
	bool _running;
	Uint64 _time_old;
	std::vector<aquatic::Fish> _fish;

public:
	static float deltaTime;
	bool Init();
	void Update();
	void Input();
	void Render();
	inline bool Running() { return _running; };

	~Game();
};

