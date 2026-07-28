
#ifndef OBJECTS_H
#define OBJECTS_H

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

void UpdateSnake(Snake *snake);
#endif

