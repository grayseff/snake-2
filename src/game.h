#ifndef GAME_H 
#define GAME_H 

#include "objects.h"

typedef struct 
{
//	int width;
//	int height;
    bool dead;	
	float move_delay;
    
	Snake snake;
    Food food;
} Game;

Game CreateGame(void);
void UpdateGame(Game *game);
void HandleInput(Game *game);

#endif
