#include "display.h"


Hex **initialize_grid(int size, int players) {
    Hex **grid = (Hex **)malloc(size * sizeof(Hex *));
    for (int i = 0; i < size; i++) {
        grid[i] = (Hex *)malloc(size * sizeof(Hex));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j].state = true;
            grid[i][j].owner = 0;
            grid[i][j].png = false;
            grid[i][j].fish_count = rand() % 3 + 1;
        }
    }

    int rows[] = {0, 4, 8, 12};
    int row_count = sizeof(rows) / sizeof(rows[0]);

    for (int i = 0; i < players; i++) {
        for (int j = 0; j < row_count; j++) {
            int k = rows[j];
            int l = rand() % GRID_WIDTH;
            while (grid[k][l].png) {
                l = rand() % GRID_WIDTH;
            }
            grid[k][l].owner = i + 1;
            grid[k][l].png = true;
            grid[k][l].fish_count = 0;
        }
    }

    return grid;
}


void upper(int r) {
    if (r%2){
        printf("    ");
    }
    for (int i = 0; i < GRID_WIDTH; i++) {
        printf("  ______  ");
    }
    printf("\n");
    if (r%2){
        printf("    ");
    }
    for (int i = 0; i < GRID_WIDTH; i++) {
        printf(" /      \\ ");
    }
    printf("\n");
    if (r%2){
        printf("    ");
    }
    for (int i = 0; i < GRID_WIDTH; i++) {
        printf("/        \\");
    }
    printf("\n");
}

void middle(Hex **grid, int r) {
    if (r%2){
        printf("    ");
    }
    for (int i = 0; i < GRID_WIDTH; i++) {
        if (grid[r][i].png) {
            printf("\\   🐧%d  /", grid[r][i].owner);
        } else {
            if (grid[r][i].fish_count == 1) {
                printf("\\   🐟   /");
            } else if (grid[r][i].fish_count == 2) {
                printf("\\  🐟🐟  /");
            } else if (grid[r][i].fish_count == 3) {
                printf("\\ 🐟🐟🐟 /");
            }
            else {
                printf("\\        /");
            }
        }
    }
    printf("\n");
    if (r%2){
        printf("    ");
    }
    for (int i = 0; i < GRID_WIDTH; i++) {
        printf(" \\______/ ");
    }
    printf("\n");
}


void print_grid(Hex **grid, Player players[], int total_players) {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        upper(i);
        middle(grid, i);
        printf("\n");
    }
    printf("\n");
    printf("\033[32mScores:\n");
    for (int i = 0; i < total_players; i++) {
        printf("Player %d: %d\n", i + 1, players[i].score);
    }
    printf("\033[0m");
    printf("\n");
}