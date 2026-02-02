#include "Game.h"


void Game::Update()
{
	player.Movement(KEY_W, KEY_S, KEY_A, KEY_D);
	Vector2 center = player.getCenter();
	Vector2 mouse_pos = { GetMousePosition() };
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		Vector2 bullet_pos{ center };

		Vector2 direction{
			mouse_pos.x - center.x,
			mouse_pos.y - center.y
		};

		Bullet bullet{
			center.x,
			center.y,
			Vector2Normalize(direction)
		};
		bullets.push_back(bullet);
	}

	for (size_t i{ 0 }; i < bullets.size(); i++)
	{
		bullets[i].Movement();
		if (bullets[i].out())
		{
			bullets[i] = bullets.back();
			bullets.pop_back();
		}
	}
	
	// to spawn with key
	//if (IsKeyPressed(KEY_SPACE))
	//{
	//	Enemy enemy{ enemy.RandomEnemySpawn() };
	//	enemies.push_back(enemy);
	//}
	start_interval += GetFrameTime();
	
	if (start_interval >= end_interval)
	{
		Enemy enemy{ enemy.RandomEnemySpawn() };
		enemies.push_back(enemy);
		start_interval = 0.0f;
	}

	for (size_t i{ 0 }; i < enemies.size(); i++)
	{
		enemies[i].Movement(player.getPosition());
		if (CheckCollisionRecs(player.getRect(), enemies[i].getRect()))
		{
			player.getLives() -= 1;
			enemies[i] = enemies.back();
			enemies.pop_back();
		}
	}

	// size_t -> unsinged integer, ko 0 - 1 velika številka
	for (int i = bullets.size() - 1; i >= 0; i--)
	{
		for (int j = enemies.size() - 1 ; j >= 0; j--)
		{
			if (CheckCollisionRecs(bullets[i].getRect(),
				enemies[j].getRect()))
			{
				bullets[i] = bullets.back();
				bullets.pop_back();
				enemies[j] = enemies.back();
				enemies.pop_back();
				break;
			}
		}
	}

}

void Game::Draw()
{
	player.Draw();
	gun.Draw(player.getCenter());
	for (size_t i{ 0 }; i < bullets.size(); i++)
	{
		bullets[i].Draw();
	}

	for (size_t i{ 0 }; i < enemies.size(); i++)
	{
		enemies[i].Draw();
	}
	
	std::string text_bullets = "Bullets: " + std::to_string(bullets.size());
	DrawText(text_bullets.c_str(), 10, 10, 50, WHITE);

	std::string text_enemies = "Enemies: " + std::to_string(enemies.size());
	DrawText(text_enemies.c_str(), 10, 60, 50, WHITE);

	std::string text_life = "Lives: " + std::to_string(player.getLives());
	DrawText(text_life.c_str(), 400, 10, 50, WHITE);
}