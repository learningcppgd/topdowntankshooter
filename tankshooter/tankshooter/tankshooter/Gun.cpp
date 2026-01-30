#include "Gun.h"



void Gun::Draw(Vector2 pivot)
{
	Vector2 mouse_position{ GetMousePosition() };
	Rectangle gun{ pivot.x , pivot.y ,size.x ,size.y };
	Vector2 origin{ 0, size.y / 2};
	Vector2 distance{
		mouse_position.x - pivot.x,
		mouse_position.y - pivot.y
	};

	float rotation = atan2f(distance.y, distance.x) * 180/PI;

	DrawRectanglePro(gun, origin, rotation, BLUE);
}