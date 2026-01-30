#pragma once
#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Gun.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <string>
struct Game
{
	Player player{};
	Gun gun{};
	std::vector <Enemy> enemies{};
	std::vector <Bullet> bullets{};
	float start_interval{ 0.0f };
	float end_interval{ 2.0f };

	void Update();
	void Draw();
};

