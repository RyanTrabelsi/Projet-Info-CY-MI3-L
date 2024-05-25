#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include "display.h"
#include "move.h"
#include "main.h"






void printCYFISH() {
    printf("  CCCCCCCCCCCC      YYYYYYY       YYYYYYY         FFFFFFFFFFFFFFFF  IIIIIIIIII  SSSSSSSSSSSSSS   HHHHHHHHHHHHHHHH  \n");
    printf(" CCC::::::::::::C     Y:::::Y       Y:::::Y        F::::::::::::::::F I::::::::I S::::::::::::::S  H::::::::::::::::H \n");
    printf("CC:::::::::::::::C     Y:::::Y       Y:::::Y       F::::::::::::::::F I::::::::I S:::::SSSSSS::::::S H:::::::HHHHHH::::::H\n");
    printf("C:::::CCCCCCCC::::C      Y::::::Y    Y:::::Y       FF::::::FFFFFFFFF II::::::II S:::::S     SSSSSSS  H::::::H     H::::::H\n");
    printf("C::::C       CCCCCC       Y:::::Y   Y:::::Y           F:::::F          I::::I   S:::::S              H:::::H     H:::::H\n");
    printf("C::::C                     Y:::::Y Y:::::Y            F:::::F          I::::I   S:::::S              H:::::H     H:::::H\n");
    printf("C::::C                      Y:::::Y:::::Y             F::::::FFFFFFFFFF I::::I    S::::SSSS           H:::::HHHHHH:::::H\n");
    printf("C::::C                       Y:::::::::Y              F:::::::::::::::F I::::I     SS::::::SSSSS      H::::::::::::::::H\n");
    printf("C::::C                        Y:::::::Y               F:::::::::::::::F I::::I       SSS::::::::SS    H:::::::HHHHHH::::::H\n");
    printf("C::::C                         Y:::::Y                F::::::FFFFFFFFFF I::::I          SSSSSS::::S   H:::::H     H:::::H\n");
    printf("C::::C                          Y:::Y                 F:::::F          I::::I               S:::::S  H:::::H     H:::::H\n");
    printf("C::::C                           YYY                  F:::::F          I::::I               S:::::S  H:::::H     H:::::H\n");
    printf("C:::::CCCCCCCC::::C              YY                 FF:::::::FF       II::::::II SSSSSSS     S:::::S H::::::H     H::::::H\n");
    printf("CC:::::::::::::::C              YY                 F::::::::FF       I::::::::I S::::::SSSSSS:::::S H::::::H     H::::::H\n");
    printf(" CCC::::::::::::C              YY                  F::::::::FF       I::::::::I S:::::::::::::::SS  H::::::H     H::::::H\n");
    printf("  CCCCCCCCCCCCC               YY                   FFFFFFFFFFF       IIIIIIIIII  SSSSSSSSSSSSSSS   HHHHHHHHH     HHHHHHHH\n");
}

void printRYAN_AMEESHA() {
    printf("\033[31m");
    printf("RRRR  Y   Y  AAAAA  N   N     +     AAAAA  M     M  EEEEE  EEEEE  SSSSS  H   H  AAAAA  \n");
    printf("R   R  Y Y   A   A  NN  N    + +    A   A  MM   MM  E      E      S      H   H  A   A  \n");
    printf("RRRR    Y    AAAAA  N N N   +++++   AAAAA  M M M M  EEEE   EEEE   SSSSS  HHHHH  AAAAA  \n");
    printf("R  R    Y    A   A  N  NN    + +    A   A  M  M  M  E      E          S  H   H  A   A  \n");
    printf("R   R   Y    A   A  N   N     +     A   A  M     M  EEEEE  EEEEE  SSSSS  H   H  A   A  \n");
    printf("\033[0m");
}

void printOptions() {
    printf("1. Jouer\n");
    printf("2. Lire les règles\n");
}

void printRules() {
    printf("Hi my little penguins! I know you are starving! I guess it is time to eat. But before\n");
    printf("you go, you know the rules, right? Oh, I know you always forget, let me remind you!\n");
    printf("\n");
    printf("        You are going to battle with your classmate on a hexagonal grid, our Iceberg,\n");
    printf("        to catch the maximum number of fish possible.\n");
    printf("        Each player starts with one fish.\n");
    printf("        Each box on the grid can contain one to three fish, which you can collect as you\n");
    printf("        move.\n");
    printf("        Each round, one of you will move from as many boxes as you want, but only\n");
    printf("        in straight lines.\n");
    printf("        You must move at least one box each turn.\n");
    printf("        If you can't move anymore, you pass your turn to your classmate.\n");
    printf("        Once you leave a box, it melts, sinks and becomes too dangerous to return to.\n");
    printf("        You can't move over a box occupied by your classmate or a box that melted.\n");
    printf("        The hunt stops when neither of you can move anymore.\n");
    printf("        Don’t worry, I will count the number of fish you collect and at the end,\n");
    printf("        I will announce the winner and show your scores.\n");
    printf("Now, let's see who catches the most fish! Happy hunting!\n");
}



void Penguin(){
    srand(time(NULL));
    int total_players;
    do {
        printf("Enter number of players (2-6): ");
        scanf("%d", &total_players);
    } while (total_players < 2 || total_players > 6);

    Player players[total_players];
    int p = 1;
    for (int i = 0; i < total_players; i++) {
        players[i].score = 0;
        players[i].penguins = 4;
    }
    Hex **grid = initialize_grid(GRID_SIZE, total_players);
    while (!game_over(players, total_players, grid)) {
        print_grid(grid, players, total_players);
        printf("Player %d, you go!\n", p);
        if (!move(grid, players, p, total_players)) {
            printf("Ouch, Player %d can't hold a finger. Let's hope he doesn't sink!\n", p);
        }
        p = p % total_players + 1;
    }
    print_grid(grid, players, total_players);
    printf("Game over!\n");
    int max_score = 0;
    int winner = 0;
    for (int i = 0; i < total_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            winner = i;
        }
    }
    printf("Player %d wins with a score of %d!\n", winner + 1, players[winner].score);

    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
}


int main() {
    int choice;
    do {
        printCYFISH();
        printRYAN_AMEESHA();
        sleep(5);
        printf("\033[H\033[J");
        printOptions();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Penguin();
                break;
            case 2:
                printf("\033[H\033[J");
                printRules();
                printf("Click on the Enter key to go back to the main menu...");
                while (getchar() != '\n');
                getchar();
                break;
            case 3:
                printf("Bye!\n");
                break;
            default:
                printf("Nope. Pick again!\n");
        }

    } while (choice != 3);
    return 0;
}
