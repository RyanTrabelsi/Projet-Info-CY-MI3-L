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


void printCYFISH();
void printRYAN_AMEESHA();
void printOptions();
void printRules();
void Penguin();
int main();
