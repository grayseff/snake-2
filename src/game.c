#include "game.h"
#include "objects.h"
#include <raylib.h>
#include <stdio.h>
#include "config.h"
Game CreateGame(void)
{
	Game game;

	game.move_delay = 0.03f;
    game.snake = GenerateSnake();
    game.food.position = GenerateFood(&game.snake);

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
void WrapPosition(Position *position)
{
    if (position->x < 0)
    {
        position->x = BOARD_WIDTH ;
    }
    else if (position->x >= BOARD_WIDTH)
    {
        position->x = 0;
    }

    if (position->y < 0)
    {
        position->y = BOARD_HEIGHT;
    }
    else if (position->y >= BOARD_HEIGHT)
    {
        position->y = 0;
    }
}
void WrapSnake(Game *game)
{
    for (int i = 0; i < game->snake.length; i++)
    {
        WrapPosition(
            &game->snake.positions[i]
        );
    }
}
void UpdateFood(Game *game)
{
    if (IsInSnake(&game->snake, game->food.position))
    {
        game->food.position = GenerateFood(&game->snake);
        GrowSnake(&game->snake);
        //later GrowSnake
    }
}

void UpdateGame(Game *game)
{
	UpdateSnake(&game->snake);
	WrapSnake(game);
    UpdateFood(game);

}
