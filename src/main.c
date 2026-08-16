#include <raylib.h>
#include <stdio.h>
#include "config.h"
#include "objects.h"
#include "game.h"
#include "render.h"
#include "audio.h"

int main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snake2");
	SetTargetFPS(TARGET_FPS);
    InitAudio();
    while (!WindowShouldClose())
    {
        Difficulty difficulty = RunMenu();
        if(difficulty == QUIT){
            return 0;
        }

	    Game game = CreateGame(); 
        game.move_delay = GetMoveDelay(difficulty);
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
            UpdateAudio();

		    BeginDrawing();
		    ClearBackground(BLACK);
		    DrawGame(&game);
		    EndDrawing();
	    }
        PlayDeathSound();
        printf("Score: %d\n",game.snake.length);
        DestroySnake(&game.snake);
    }
    DestroyAudio();
	CloseWindow();
	return 0;
}
