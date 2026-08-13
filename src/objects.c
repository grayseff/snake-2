#include "objects.h"
#include "config.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
Snake GenerateSnake(void)
{
    Snake snake;

    snake.length=1;
    snake.capacity = 10;
    snake.positions = malloc(snake.capacity * sizeof(Position));
    if (snake.positions == NULL)
    {
        fprintf(stderr, "Failed to Allocate Memory to Snake.\n");
        exit(EXIT_FAILURE);
    }
    snake.positions[0] = (Position){
        BOARD_WIDTH/2,
        BOARD_HEIGHT/2
    };
    snake.direction=RIGHT;
    


    return snake;
}
void DestroySnake(Snake *snake)
{
    free(snake->positions);
}

void UpdateSnake(Snake *snake)
{
    for (int i=snake->length -1; i > 0 ; i-- )
    {
        snake->positions[i] = snake->positions[i - 1];
    }

	switch (snake->direction)
	{
		case UP:
		snake -> positions[0].y-- ;
		break;

		case DOWN:
		snake -> positions[0].y++ ;
		break;

		case LEFT:
		snake -> positions[0].x-- ;
		break;

		case RIGHT:
		snake -> positions[0].x++ ;
		break;
	}
}
bool IsInSnake(Snake *snake, Position position)
{
    
    for (int i = 0; i<snake->length;i++)
    {
    if  (   position.x < snake->positions[i].x + CHAR_SIZE &&
            position.x + CHAR_SIZE > snake->positions[i].x &&
            position.y < snake->positions[i].y + CHAR_SIZE &&
            position.y + CHAR_SIZE > snake->positions[i].y) {
        return true;
        }
    }
    return false;

}
bool IsCannibal(Snake *snake)
{
    for (int i = 1; i<snake->length;i++)
    {
        if (    snake->positions[0].x < snake->positions[i].x + CHAR_SIZE &&
                snake->positions[0].x + CHAR_SIZE > snake->positions[i].x &&
                snake->positions[0].y < snake->positions[i].y + CHAR_SIZE &&
                snake->positions[0].y + CHAR_SIZE > snake->positions[i].y)
        {   return true;
        }
    }
        return false;
}
Position GenerateFood(Snake *snake)
{
    Position position;
    do 
    {
        position.x = GetRandomValue(0, BOARD_WIDTH - CHAR_SIZE);
        position.y = GetRandomValue(0, BOARD_HEIGHT - CHAR_SIZE);

    } 
    while (IsInSnake(snake,position));
    
    return position;
}
void GrowSnake(Snake *snake)
{
    if (snake->length == snake->capacity)
    {
        snake -> capacity *= 2;

        Position *positions = realloc(
                snake->positions,
                snake->capacity * sizeof(Position)
                );
        if (positions == NULL)
        {
            fprintf(stderr, "Failed to grow snake.\n");
            exit(EXIT_FAILURE);
        }
        snake->positions = positions;
    }
    Position tail = snake->positions[snake->length - 1];
    switch (snake->direction)
    {
        case UP:
            tail.y +=CHAR_SIZE;
            break;
        case DOWN:
            tail.y -= CHAR_SIZE;
            break;
        case LEFT:
            tail.x += CHAR_SIZE;
            break;
        case RIGHT:
            tail.x -= CHAR_SIZE;
            break;
    }
    snake->length++;
    snake->positions[snake->length - 1] = tail;
}

