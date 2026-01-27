#include "Gun.h"


Gun::Gun()
{
	gun = { 0,0,width, height };
}

/// <summary>
/// x and y are players central coordinates
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Gun::Draw(float x, float y) {
    float rotation = atan2(player_direction.y, player_direction.x) * (180.0f / PI);

    Vector2 origin = { 0, height / 2 };
    Rectangle dest = { x, y, width, height };

    DrawRectanglePro(dest, origin, rotation, BLUE);
}