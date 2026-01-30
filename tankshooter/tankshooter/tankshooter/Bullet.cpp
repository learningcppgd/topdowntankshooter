#include "Bullet.h"


Bullet::Bullet(float x, float y, Vector2 dir)
{
	position = { x,y };
	direction = { dir };
}

void Bullet::Movement()
{
	position.x += direction.x * speed * GetFrameTime();
	position.y += direction.y * speed * GetFrameTime();
}

void Bullet::Draw()
{
	DrawRectangle(position.x, position.y, size.x, size.y, YELLOW);
}