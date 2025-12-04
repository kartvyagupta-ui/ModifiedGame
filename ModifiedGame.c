#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int x = 1;                // player position (0-2)
    int step = 0;             // obstacle vertical movement
    int obstaclePos = rand() % 3;
    int score = 0;            // score counter
    int lives = 3;            // player lives
    int speed = 150;          // initial speed (ms delay)
    
    while (1) {

        // -------- INPUT --------
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)   // LEFT arrow
                x--;

            if (ch == 77 && x < 2)   // RIGHT arrow
                x++;
        }

        // -------- DRAW --------
        system("cls");
        printf("=== SIMPLE CAR GAME ===\n");
        printf("Score: %d   Lives: %d\n", score, lives);
        printf("------------------------\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {  // obstacle row
                if (obstaclePos == 0)
                    printf("| @         |\n");
                else if (obstaclePos == 1)
                    printf("|     @     |\n");
                else
                    printf("|         @ |\n");
            } else {
                printf("|           |\n");
            }
        }

        // Draw player
        if (x == 0)
            printf("| ^         |\n");
        else if (x == 1)
            printf("|     ^     |\n");
        else
            printf("|         ^ |\n");

        // -------- COLLISION --------
        if (step == 10 && x == obstaclePos) {
            lives--;
            printf("Collision! Lives left: %d\n", lives);
            Sleep(700);

            // Reset obstacle
            step = 0;
            obstaclePos = rand() % 3;

            if (lives == 0) {
                printf("GAME OVER!\nFinal Score: %d\n", score);
                break;
            }
        }

        Sleep(speed);

        // Move obstacle down
        step++;

        // -------- RESET OBSTACLE --------
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 0;
}
