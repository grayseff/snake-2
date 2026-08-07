#include "render.h"
#include "config.h"
#include <raylib.h>



void DrawSnake(Snake *snake)
{
	DrawRectangle(
			snake->position.x * GRID_SIZE ,
			snake->position.y * GRID_SIZE ,
			CELL_SIZE,
			CELL_SIZE,
			GREEN);
}

void DrawGame(Game *game)
{	
	DrawSnake(&game->snake);
}
