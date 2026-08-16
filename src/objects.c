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
    snake.positions = malloc(snake.capacity *CHAR_SIZE* sizeof(Position));
    if (snake.positions == NULL)
    {
        fprintf(stderr, "Failed to Allocate Memory to Snake.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        snake.positions[i].x = BOARD_WIDTH / 2 - i;
        snake.positions[i].y = BOARD_HEIGHT / 2;
    }
    snake.direction=RIGHT;
    snake.next_direction=RIGHT;  


    return snake;
}
void DestroySnake(Snake *snake)
{
    free(snake->positions);
}

void UpdateSnake(Snake *snake)
{
    snake->direction = snake->next_direction;
    for (int i=snake->length*CHAR_SIZE -1; i > 0 ; i-- )
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
    
    for (int i = 0; i<snake->length*CHAR_SIZE;i++)
    {
            Position snake_position = snake->positions[i];
    
    if  (   position.x < snake_position.x + CHAR_SIZE &&
            position.x + CHAR_SIZE > snake_position.x &&
            position.y < snake_position.y + CHAR_SIZE &&
            position.y + CHAR_SIZE > snake_position.y) {
        return true;
        }
    }
    return false;

}
bool IsCannibal(Snake *snake)
{
    Position head = snake->positions[0];

    for (int i = 1; i < snake->length; i++)
        {
            Position body = snake->positions[i * CHAR_SIZE];

            switch (snake->direction)
            {
                case RIGHT:
                    // leading (right) edge of head
                    if (head.x + CHAR_SIZE > body.x &&
                        head.x + CHAR_SIZE <= body.x + CHAR_SIZE &&
                        head.y >= body.y &&
                        head.y + CHAR_SIZE <= body.y + CHAR_SIZE)
                {
                    return true;
                }
                    break;

            case LEFT:
                // leading (left) edge of head
                if (head.x < body.x + CHAR_SIZE &&
                    head.x >= body.x &&
                    head.y >= body.y &&
                    head.y + CHAR_SIZE <= body.y + CHAR_SIZE)
                {
                    return true;
                }
                break;

            case DOWN:
                // leading (bottom) edge of head
                if (head.y + CHAR_SIZE > body.y &&
                    head.y + CHAR_SIZE <= body.y + CHAR_SIZE &&
                    head.x >= body.x &&
                    head.x + CHAR_SIZE <= body.x + CHAR_SIZE)
                {
                    return true;
                }
                break;

            case UP:
                // leading (top) edge of head
                if (head.y < body.y + CHAR_SIZE &&
                    head.y >= body.y &&
                    head.x >= body.x &&
                    head.x + CHAR_SIZE <= body.x + CHAR_SIZE)
                {
                    return true;
                }
                break;
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
                snake->capacity *CHAR_SIZE* sizeof(Position)
                );
        if (positions == NULL)
        {
            fprintf(stderr, "Failed to grow snake.\n");
            exit(EXIT_FAILURE);
        }
        snake->positions = positions;
    }
    Position tail = snake->positions[snake->length*CHAR_SIZE - 1 ];

    for (int i = snake->length * CHAR_SIZE;
            i<(snake->length+1) * CHAR_SIZE;
            i++) {
        snake->positions[i] = tail;
    }

    snake->length++;
}

