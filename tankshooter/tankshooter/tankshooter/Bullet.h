#pragma once
#include "raylib.h"
class Bullet
{
private:
	Vector2 position;
	Vector2 direction;
	Vector2 size{ 5.0f,5.0f };
	float speed{ 400.0f };
public:
	Bullet(float x, float y, Vector2 dir);

	void Movement();
	void Draw();

};

