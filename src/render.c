#include "render.h"
#include "config.h"
#include <raylib.h>


//void DrawSnake(Snake *snake)
//{
//	DrawRectangle(
//			snake->position.x * GRID_SIZE ,
//			snake->position.y * GRID_SIZE ,
//			CELL_SIZE,
//			CELL_SIZE,
//			GREEN);
//}
void DrawSnake(Snake *snake)
{
    for (int i = 0; i < snake->length; i++)
    {
        float t = 0.0f;

        if (snake->length > 1)
        {
            t = (float)i / (snake->length - 1);
        }

        Color color = {
            255 - (unsigned char)(235 * t),
            255 - (unsigned char)(155 * t),
            255 - (unsigned char)(215 * t),
            255
        };

        DrawRectangle(
            snake->positions[i].x * GRID_SIZE,
            snake->positions[i].y * GRID_SIZE,
            CELL_SIZE,
            CELL_SIZE,
            color
        );
    }
}
void DrawFood(Food *food)
{
    DrawRectangle(
            food->position.x*GRID_SIZE, 
            food->position.y*GRID_SIZE, 
            CELL_SIZE, 
            CELL_SIZE, 
            RED);
}
void DrawGame(Game *game)
{	
	DrawSnake(&game->snake);
    DrawFood(&game->food);
}
