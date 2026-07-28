#include "objects.h"

void UpdateSnake(Snake *snake)
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

