#include "move.h"



int valid_move(Hex **grid, int start_x, int start_y, int end_x, int end_y) {
    if (end_x < 0 || end_x >= GRID_SIZE || end_y < 0 || end_y >= GRID_WIDTH) {
        return 0;
    }
    if (grid[end_x][end_y].owner != 0 || grid[end_x][end_y].fish_count == 0) {
        return 0;
    }
    if (start_x != end_x && start_y != end_y) {
        return 0;
    }
    if (start_x == end_x) {
        int min_y = start_y < end_y ? start_y : end_y;
        int max_y = start_y > end_y ? start_y : end_y;
        for (int y = min_y + 1; y < max_y; y++) {
            if (grid[start_x][y].owner != 0 || grid[start_x][y].fish_count == 0) {
                return 0;
            }
        }
    } else {
        int min_x = start_x < end_x ? start_x : end_x;
        int max_x = start_x > end_x ? start_x : end_x;
        for (int x = min_x + 1; x < max_x; x++) {
            if (grid[x][start_y].owner != 0 || grid[x][start_y].fish_count == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int move(Hex **grid, Player players[], int p, int total_players) {
    int a, b, x, y;
    bool good = false;

    while (!good) {
        printf("Player %d, choose your penguin! (Row then Column):\n", p);
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (a < 0 || a >= GRID_SIZE || b < 0 || b >= GRID_WIDTH || grid[a][b].owner != p) {
            printf("Come on, let's not steal from others! Pick your own penguin!.\n");
        } else {
            good = true;
        }
    }

    good = false;

    while (!good) {
        printf("Where to go? (Row then Column):\n");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (valid_move(grid, a, b, x, y)) {
            grid[x][y].owner = p;
            grid[x][y].png = true;
            grid[a][b].owner = 0;
            grid[a][b].png = false;
            players[p - 1].score += grid[x][y].fish_count;
            grid[x][y].fish_count = 0;
            printf("You got it!\n");
            return 1;
        } else {
            printf("Uh-uh, seems like it ain't right! Pick again!.\n");
        }
    }
    return 0;
}

int game_over(Player players[], int player_count, Hex **grid) {
    for (int i = 0; i < player_count; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            for (int k = 0; k < GRID_WIDTH; k++) {
                if (grid[j][k].owner == i + 1) {
                    if (valid_move(grid, j, k, j-1, k)) {
                        return 0;
                    }
                    if (valid_move(grid, j, k, j+1, k)) {
                        return 0;
                    }
                    if (valid_move(grid, j, k, j, k-1)) {
                        return 0;
                    }
                    if (valid_move(grid, j, k, j, k+1)) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
