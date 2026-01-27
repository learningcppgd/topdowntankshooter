#include "Player.h"

Player::Player()
{
	position = { 400.0f, 400.0f };
	speed = { 400.0f, 400.0f };
	player = { position.x, position.y, 50,50 };
}

void Player::Movement(KeyboardKey up, KeyboardKey down, KeyboardKey left, KeyboardKey right)
{
	Vector2 direction{ 0.0f, 0.0f };

	if (IsKeyDown(up)) direction.y -= 1.0f;
	if (IsKeyDown(down)) direction.y += 1.0f;
	if (IsKeyDown(left)) direction.x -= 1.0f;
	if (IsKeyDown(right)) direction.x += 1.0f;

	if (CheckDistance(direction) > 1)
	{
		direction = Vector2Normalize(direction);
	}

	position.x += direction.x * speed.x * GetFrameTime();
	position.y += direction.y * speed.y * GetFrameTime();

	player.x = position.x;
	player.y = position.y;
}

void Player::Draw()
{
	DrawRectangleRec(player, RED);
}

float Player::CheckDistance(Vector2 v1)
{
	return sqrt(v1.x * v1.x + v1.y * v1.y);
}

Vector2 Player::CenterofRectPoint()
{
	Vector2 center{};
	float centerx{ float(player.x + player.width / 2) };
	float centery{ float(player.y + player.height / 2) };
	return center = { centerx, centery };
}