#include "Game.h"


void Game::Draw()
{
	player.Draw();
	gun.Draw(player.CenterofRectPoint().x, player.CenterofRectPoint().y);
}

void Game::Update()
{
	getDirection();
	player.Movement(KEY_W, KEY_S, KEY_A, KEY_D);
	std::cout << gun.getPlayerDirection().x << " " << gun.getPlayerDirection().y << '\n';
}

void Game::getDirection()
{
	Vector2 mouse_pos = GetMousePosition();
	Vector2 player_pos = player.CenterofRectPoint();
	gun.getPlayerDirection() =
		Vector2Normalize({ mouse_pos.x - player_pos.x, mouse_pos.y - player_pos.y });
}



