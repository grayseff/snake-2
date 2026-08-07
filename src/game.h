#ifndef GAME_H 
#define GAME_H 

#include "objects.h"

typedef struct 
{
	int width;
	int height;
	
	float move_delay;

	Snake snake;
} Game;

Game CreateGame(int width, int height);
void UpdateGame(Game *game);
void HandleInput(Game *game);

#endif
