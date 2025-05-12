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
        printf("�K�X���~�W�L�T���A�{�������C\n");
        return 0;
    }

    while (1) {
        showMenu();
        printf("�п�J�ﶵ (a/b/c/d): ");
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
                printf("��J���~�A�Э��s��ܡC\n");
        }
    }

    return 0;
}
