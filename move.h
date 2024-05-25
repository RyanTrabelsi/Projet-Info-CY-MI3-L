#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define MAX_PLAYERS 6
#define GRID_SIZE 13
#define GRID_WIDTH 6


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
