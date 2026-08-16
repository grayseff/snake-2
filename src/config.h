#ifndef CONFIG_H
#define CONFIG_H

#define GRID_SIZE    10
#define CHAR_SIZE    2//4

#define CELL_SIZE   (GRID_SIZE*CHAR_SIZE)

#define BOARD_WIDTH  80
#define BOARD_HEIGHT 60

#define WINDOW_WIDTH  (BOARD_WIDTH * GRID_SIZE)
#define WINDOW_HEIGHT (BOARD_HEIGHT * GRID_SIZE)

#define TARGET_FPS   60

typedef enum
{
    EASY,
    NORMAL,
    HARD,
    QUIT
} Difficulty;
float GetMoveDelay(Difficulty difficulty);
Difficulty RunMenu(void);

#endif
