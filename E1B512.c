#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ROWS 9
#define COLS 9
#define PASSWORD 2025
#define MAX_ATTEMPTS 3

char seats[ROWS][COLS];
char input[100];


void printWelcome();
int checkPassword();
void showMenu();
void showSeats();
void generateRandomSeats();
void waitForEnter();
void arrangeSeats();
int isAvailable(int r, int c);
int findConsecutiveSeats(int count, int *r, int *c);
void confirmArrangement(int r[], int c[], int count);
void chooseByUser();
int isValidFormat(const char *s, int *r, int *c);
void exitProgram();
int main() {
    srand(time(NULL));
    generateRandomSeats();

    printWelcome();
    if (!checkPassword()) {
        printf("密碼錯誤超過三次，程式結束。\n");
        return 0;
    }

    while (1) {
        showMenu();
        printf("請輸入選項 (a/b/c/d): ");
        fgets(input, sizeof(input), stdin);
        char choice = tolower(input[0]);

        switch (choice) {
            case 'a':
                showSeats();
                waitForEnter();
                break;
            case 'b':
                arrangeSeats();
                break;
            case 'c':
                chooseByUser();
                break;
            case 'd':
                exitProgram();
                break;
            default:
                printf("輸入錯誤，請重新選擇。\n");
        }
    }

    return 0;
}
