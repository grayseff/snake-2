#include "config.h"
#include <raylib.h>

float GetMoveDelay(Difficulty difficulty)
{
    switch (difficulty)
    {
        case EASY:
            return 0.10f;

        case NORMAL:
            return 0.05f;
        case HARD:
            return 0.02f;
        case QUIT:
            return 0.00f;
    }
    return 0.05f;
}
Difficulty RunMenu(void)
{
    Difficulty difficulty = NORMAL;
    while(!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE))
            difficulty = EASY;

        if (IsKeyPressed(KEY_TWO))
            difficulty = NORMAL;

        if (IsKeyPressed(KEY_THREE))
            difficulty = HARD;

        if (IsKeyPressed(KEY_ENTER))
            return difficulty;

        if (IsKeyPressed(KEY_Q))
            return QUIT;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("SNAKE", 100, 100, 40, WHITE);

        DrawText("1 - Easy",   100, 180, 20, WHITE);
        DrawText("2 - Normal", 100, 220, 20, WHITE);
        DrawText("3 - Hard",   100, 260, 20, WHITE);

        DrawText("ENTER - Start", 100, 340, 20, WHITE);
        DrawText("Q - Quit",      100, 380, 20, WHITE);

        EndDrawing();
    }
    return QUIT;
}
