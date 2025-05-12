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
void printWelcome() {
    for (int i = 0; i < 20; i++) {
        printf("=== 歡迎使用訂位系統 ===\n");
    }
}


int checkPassword() {
    int attempt = 0, user_input;

    while (attempt < MAX_ATTEMPTS) {
        printf("請輸入四位數密碼：");
        scanf("%d", &user_input);
        getchar(); // 吃掉換行
        if (user_input == PASSWORD) {
            printf("密碼正確，歡迎進入系統！\n");
            return 1;
        } else {
            printf("密碼錯誤！\n");
            attempt++;
        }
    }
    return 0;
}

void showMenu() {
    printf("\n----------[訂位系統]----------\n");
    printf("|  a. 查看可用座位            |\n");
    printf("|  b. 系統自動安排座位        |\n");
    printf("|  c. 自行選擇座位            |\n");
    printf("|  d. 離開系統                |\n");
    printf("--------------------------------\n");
}


void generateRandomSeats() {
    int count = 0;
    memset(seats, '-', sizeof(seats));

    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}


void showSeats() {
    printf(" \\123456789\n");
    for (int r = ROWS - 1; r >= 0; r--) {
        printf("%d", r + 1);
        for (int c = 0; c < COLS; c++) {
            printf("%c", seats[r][c]);
        }
        printf("\n");
    }
}


void waitForEnter() {
    printf("按 Enter 鍵回到主選單...");
    getchar();
}


void arrangeSeats() {
    int count;
    int r[4], c[4];

    printf("請問需要幾個座位 (1~4)：");
    scanf("%d", &count);
    getchar();
    if (count < 1 || count > 4) {
        printf("輸入人數無效。\n");
        return;
    }

    if (!findConsecutiveSeats(count, r, c)) {
        printf("找不到合適的連續座位。\n");
        return;
    }

