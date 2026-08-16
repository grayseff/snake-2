
#ifndef OBJECTS_H
#define OBJECTS_H
#include <stdbool.h>
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
	Position *positions;
    int length;
    int capacity;
	Direction direction;
    Direction next_direction;
} Snake;

typedef struct
{
 Position position;
 bool active;
} Food;


bool IsInSnake(Snake *snake, Position position);
Position GenerateFood(Snake *snake);
void UpdateSnake(Snake *snake);
Snake GenerateSnake(void);
void DestroySnake(Snake *snake);
bool IsCannibal(Snake *snake);
void GrowSnake(Snake *snake);
#endif

