#include "display.h"


typedef struct {
    int score;
    int penguins;
} Player;

typedef struct {
    bool state;
    int owner;
    bool png;
    int fish_count;
} Hex;


int valid_move(Hex **grid, int start_x, int start_y, int end_x, int end_y);
int move(Hex **grid, Player players[], int p, int total_players);
int game_over(Player players[], int player_count, Hex **grid);
