/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int guess;
    int jackpot;
    int attempt;
    time_t start;
    const time_t COUNT_DOWN = 15;
    time_t stop;
    const int MAX_ATTEMPTS = 5;

    srand(time(NULL));
    jackpot = rand() % 100;
    start = time(NULL);
    stop = start + COUNT_DOWN;
    printf("You have 15 sec to attempt 5 times\n");

    for (attempt = 1; attempt <= MAX_ATTEMPTS; ++attempt) {
        printf("Your %d attempt\n", attempt);
        printf("Please enter the magic no between 1-100 to win" \
                " the lottery :");
        scanf("%d", &guess);
        if (time(NULL) > stop) {
            printf("you lost to time\n");
            break;
        }
        if (jackpot == guess) {
            printf("\033[1;34m");
            printf("you  got a jackpot\n");
            printf("\033[0m;");
            break;
        }
        if (guess > 100 || guess < 0) {
            printf("\033[1;31m");
            printf("invalid output\n");
            printf("\033[0m;");
        } else {
            if (guess > jackpot) {
                printf("\033[1;32m");
                printf("guess a bit lower\n");
                printf("\033[0m");
            } else if (guess < jackpot) {
                printf("\033[1;32m");
                printf("guess a bit higher\n");
                printf("\033[0m");
            }
        }
    }
    printf("%d IS THE CORRECT ANSWER", jackpot);

    return EXIT_SUCCESS;
}
