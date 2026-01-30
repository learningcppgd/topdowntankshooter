#include <iostream>
#include "raylib.h"
#include "Game.h"
int main()
{
	InitWindow(800, 800, "Tank");
	SetTargetFPS(60);
	Game game;

	while (!WindowShouldClose())
	{
		game.Update();

		BeginDrawing();
		ClearBackground(DARKGRAY);
		game.Draw();
		EndDrawing();
	}
	CloseWindow();
}