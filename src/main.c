#include <raylib.h>
#include <stdio.h>
#include "config.h"
#include "objects.h"
#include "game.h"
#include "render.h"
int main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snake2");
	SetTargetFPS(60);


	Game game = CreateGame(); 

	float timer = 0.0f;

	while (!WindowShouldClose() && !game.dead) 
	{

		HandleInput(&game);
		timer += GetFrameTime();

		if (timer >= game.move_delay)
		{
			UpdateGame(&game);
			timer -= game.move_delay;
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawGame(&game);
		EndDrawing();
	}
    printf("Score: %d\n",game.snake.length);

    DestroySnake(&game.snake);
	CloseWindow();
	return 0;
}
