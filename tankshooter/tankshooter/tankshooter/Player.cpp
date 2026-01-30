#include "Player.h"


void Player::Movement(KeyboardKey up, KeyboardKey down,
	KeyboardKey left, KeyboardKey right)
{
	Vector2 direction{ 0.0f,0.0f };

	if (IsKeyDown(up)) direction.y -= 1.0f;
	if (IsKeyDown(down)) direction.y += 1.0f;
	if (IsKeyDown(left)) direction.x -= 1.0f;
	if (IsKeyDown(right)) direction.x += 1.0f;

	if (Vector2Length(direction) > 1.0f)
	{
		direction = Vector2Normalize(direction);
	}

	position.x += speed * direction.x * GetFrameTime();
	position.y += speed * direction.y * GetFrameTime();
	
	//limiting = Clamp(value, min, max)
	position.x = Clamp(position.x, 0, GetScreenWidth() - size.x);
	position.y = Clamp(position.y, 0, GetScreenHeight() - size.y);
}

void Player::Draw()
{
	DrawRectangleV(position, size, RED);
}