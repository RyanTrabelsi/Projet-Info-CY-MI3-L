#include "move.h"


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
