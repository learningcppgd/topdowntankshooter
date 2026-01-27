#include "raylib.h"
#include "raymath.h"

#pragma once
 class Player
{
private:
	Vector2 position;
	Vector2 speed;
	Rectangle player;

public:
	Player();
	void Draw();
	void Movement(KeyboardKey up, KeyboardKey down, KeyboardKey left, KeyboardKey right);
	float CheckDistance(Vector2 v1);
	Vector2 CenterofRectPoint();

	Rectangle getRectangle() { return player; }
};

