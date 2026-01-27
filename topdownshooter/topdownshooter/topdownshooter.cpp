#include <iostream>
#include "raylib.h"
#include "Game.h"

const float SCREENWIDTH{ 800.0f };
const float SCREENHEIGHT{ 800.0f };
const int FPS{ 60 };

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "TOP DOWN SHOOTER");
	SetTargetFPS(FPS);

	Game game{};

	while (!WindowShouldClose())
	{
		//UPDATE
		game.Update();

		BeginDrawing();
		ClearBackground(DARKGRAY);
		game.Draw();
		EndDrawing();

	}

	CloseWindow();

	return 0;
}