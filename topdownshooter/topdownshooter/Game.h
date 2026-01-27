#include "raylib.h"
#include "Player.h"
#include "Gun.h"
#include "raymath.h"
#pragma once
class Game
{
public:
	Player player{};
	Gun gun{};


	void Update();
	void Draw();
	void getDirection();
};

