#include "raylib.h"
#include <iostream>
#pragma once
class Gun
{
private:
	Rectangle gun;
	float offset{40};
	float width{ 25 };
	float height{ 15 };
	Vector2 player_direction{1,0};
public:
	Gun();

	void Draw(float x, float y);

	Rectangle& getRect() { return gun; }
	float getOffset() { return offset; }
	Vector2& getPlayerDirection() { return player_direction; }
};

