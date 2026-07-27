#include <raylib.h>


typedef struct {
	int x; 
	int y;

} Position;
typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
} Direction;
typedef struct
{
	Position position;
	Direction direction;
} Snake;


void UpdateGame(Snake *snake)
{
	switch (snake->direction)
	{
		case UP:
		snake -> position.y-- ;
		break;

		case DOWN:
		snake -> position.y++ ;
		break;

		case LEFT:
		snake -> position.x-- ;
		break;

		case RIGHT:
		snake -> position.x++ ;
		break;
	}
}
void HandleInput(Snake *snake)
{
	if (IsKeyPressed(KEY_UP) && snake->direction != DOWN)
	{
		snake->direction = UP;
	}
	if (IsKeyPressed(KEY_DOWN) && snake->direction != UP)
	{
		snake->direction = DOWN;
	}
	if (IsKeyPressed(KEY_LEFT) && snake->direction != RIGHT)
	{
		snake->direction = LEFT;
	}
	if (IsKeyPressed(KEY_RIGHT) && snake->direction != LEFT)
	{
		snake->direction = RIGHT;
	}
}


int main(void)
{
	InitWindow(800, 600, "snake2");
	SetTargetFPS(60);

	int x = 100;
	int y = 100;

	Snake snake = {
		.position = {10, 10},
		.direction = RIGHT,
	};



	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		HandleInput(&snake);
		UpdateGame(&snake);
		DrawRectangle(snake.position.x, snake.position.y, 20, 20, GREEN);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
