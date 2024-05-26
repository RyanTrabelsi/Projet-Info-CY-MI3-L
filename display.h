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

Hex **initialize_grid(int size, int players);
void upper(int r);
void middle(Hex **grid, int r);
void print_grid(Hex **grid, Player players[], int total_players);