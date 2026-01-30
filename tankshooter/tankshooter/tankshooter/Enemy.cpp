#include "Enemy.h"

Enemy::Enemy(Vector2 pos)
{
	position = {pos};
}

void Enemy::Movement(Vector2 player_pos)
{
	Vector2 dir = Vector2Normalize(Vector2Subtract(player_pos, position));
	position.x += dir.x * speed * GetFrameTime();
	position.y += dir.y * speed * GetFrameTime();
}

void Enemy::Draw()
{
	DrawRectangle(position.x, position.y, size.x, size.y, WHITE);
}

Vector2 Enemy::RandomEnemySpawn()
{
    int side = GetRandomValue(0, 3); 

    switch (side)
    {
    case 0: //top
        return {
            (float)GetRandomValue(0, GetScreenWidth()), -50.0f
        };

    case 1: // right
        return {
            (float)GetScreenWidth() + 50.0f,
            (float)GetRandomValue(0, GetScreenHeight())
        };

    case 2: // bot
        return {
            (float)GetRandomValue(0, GetScreenWidth()),
            (float)GetScreenHeight() + 50.0f
        };

    case 3:// left
        return { 
            -50.0f,
            (float)GetRandomValue(0, GetScreenHeight())
        };
    }

    return { 0, 0 };
}