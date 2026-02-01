#pragma once
#include "raylib.h"
#include "raymath.h"
class Enemy
{
private:
	Vector2 position;
	Vector2 size{ 20,20 };
	Vector2 direction{0,0};
	float speed{ 100.0f };

public:
	Enemy(Vector2 pos);

	void Movement(Vector2 player_pos);
	void Draw();
	Vector2 RandomEnemySpawn();
	Rectangle getRect() {
		return Rectangle{ position.x, position.y, size.x, size.y };
	}
};

