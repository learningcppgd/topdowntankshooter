#pragma once
#include "raylib.h"
#include "raymath.h"
class Gun
{
private:
	Vector2 size{ 20,10 };
public:

	void Draw(Vector2 pivot);

	Vector2 getSize() { return size; }
};

