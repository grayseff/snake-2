#include <raylib.h>
#include "config.h"
#include "objects.h"
#include "game.h"
#include "render.h"
int main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snake2");
	SetTargetFPS(60);


	Game game = CreateGame(BOARD_WIDTH,BOARD_HEIGHT); 

	float timer = 0.0f;

	while (!WindowShouldClose()) 
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
	CloseWindow();
	return 0;
}
