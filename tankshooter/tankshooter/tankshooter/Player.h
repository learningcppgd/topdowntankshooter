#pragma once
#include "raylib.h"
#include "raymath.h"
#include <iostream>
class Player
{
private:
	Vector2 position{ 400,400 };
	Vector2 size{ 40.0f,40.0f };
	float speed{300.0f};
	int life{ 10 };
public:
	void Movement(KeyboardKey up, KeyboardKey down,
		KeyboardKey left, KeyboardKey right);
	void Draw();

	//getters
	Vector2 getPosition() { return position; }
	Vector2 getSize() { return size; }
	Vector2 getCenter()
	{
		return { position.x + size.x / 2.0f, position.y + size.y / 2.0f };
	}
	Rectangle getRect() {
		return Rectangle{ position.x, position.y, size.x, size.y };
	}
	int& getLives() { return life; }
};

