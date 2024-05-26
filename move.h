#include "display.h"



int valid_move(Hex **grid, int start_x, int start_y, int end_x, int end_y);
int move(Hex **grid, Player players[], int p, int total_players);
int game_over(Player players[], int player_count, Hex **grid);
