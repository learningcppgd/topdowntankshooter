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
	for (Bullet& i : bullets)
	{
		i.Movement();
	}
	
	// to spawn with key
	//if (IsKeyPressed(KEY_SPACE))
	//{
	//	Enemy enemy{ enemy.RandomEnemySpawn() };
	//	enemies.push_back(enemy);
	//}
	start_interval += GetFrameTime();
	std::cout << start_interval << '\n';
	
	if (start_interval >= end_interval)
	{
		Enemy enemy{ enemy.RandomEnemySpawn() };
		enemies.push_back(enemy);
		start_interval = 0.0f;
	}

	for (Enemy& i : enemies)
	{
		i.Movement(player.getPosition());
	}


}

void Game::Draw()
{
	player.Draw();
	gun.Draw(player.getCenter());
	for (Bullet& i : bullets)
	{
		i.Draw();
	}

	for (Enemy& i : enemies)
	{
		i.Draw();
	}

	
	std::string text = "Bullets: " + std::to_string(bullets.size());
	DrawText(text.c_str(), 10, 10, 50, WHITE);
}