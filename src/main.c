#include <raylib.h>
#include "objects.h"
#include "game.h"
int main(void)
{
	InitWindow(800, 600, "snake2");
	SetTargetFPS(60);

	int x = 100;
	int y = 100;

	Game game = CreateGame(800,600); 


	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		HandleInput(&game);
		UpdateGame(&game);
		DrawRectangle(game.snake.position.x, game.snake.position.y, 20, 20, GREEN);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
