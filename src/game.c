#include "game.h"
#include <raylib.h>
#include <stdio.h>
Game CreateGame(int width, int height)
{
	Game game;
	game.width = width;
	game.height = height;
	game.move_delay = 0.03f;
	game.snake.position.x = width / 2;
	game.snake.position.y = height / 2;
	game.snake.direction = RIGHT;

	return game;
}



void HandleInput(Game *game)
{
	if (IsKeyPressed(KEY_UP) && game->snake.direction != DOWN)
	{
		game->snake.direction = UP;
	}
	if (IsKeyPressed(KEY_DOWN) && game->snake.direction != UP)
	{
		game->snake.direction = DOWN;
	}
	if (IsKeyPressed(KEY_LEFT) && game->snake.direction != RIGHT)
	{
		game->snake.direction = LEFT;
	}
	if (IsKeyPressed(KEY_RIGHT) && game->snake.direction != LEFT)
	{
		game->snake.direction = RIGHT;
	}
}

void WrapSnake(Game *game)
{
	Snake *snake = &game->snake ; 
	if (snake->position.x < 0)
	{
		snake->position.x = game->width - 1;
	}
	else if (snake->position.x > game->width)
	{
		snake->position.x = 0;
	}
	else if (snake->position.y < 0)
	{
		snake->position.y = game->height - 1;
	}
	else if (snake->position.y > game->height)
	{
		snake->position.y = 0;
	}
}

void UpdateGame(Game *game)
{
	UpdateSnake(&game->snake);
	WrapSnake(game);

}
