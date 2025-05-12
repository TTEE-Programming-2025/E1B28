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
    for (int i = 0; i < count; i++)
        seats[r[i]][c[i]] = '@';

    showSeats();
    printf("是否滿意此安排？(y/n)：");
    fgets(input, sizeof(input), stdin);

    if (tolower(input[0]) == 'y') {
        confirmArrangement(r, c, count);
    } else {
        for (int i = 0; i < count; i++)
            seats[r[i]][c[i]] = '-';
    }
}

int isAvailable(int r, int c) {
    return seats[r][c] == '-';
}


int findConsecutiveSeats(int count, int *r_out, int *c_out) {

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c <= COLS - count; c++) {
            int ok = 1;
            for (int k = 0; k < count; k++) {
                if (!isAvailable(r, c + k)) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                for (int k = 0; k < count; k++) {
                    r_out[k] = r;
                    c_out[k] = c + k;
                }
                return 1;
            }
        }
    }

    if (count == 4) {
        for (int r = 0; r < ROWS - 1; r++) {
            for (int c = 0; c <= COLS - 2; c++) {
                if (isAvailable(r, c) && isAvailable(r, c + 1) &&
                    isAvailable(r + 1, c) && isAvailable(r + 1, c + 1)) {
                    r_out[0] = r;     c_out[0] = c;
                    r_out[1] = r;     c_out[1] = c + 1;
                    r_out[2] = r + 1; c_out[2] = c;
                    r_out[3] = r + 1; c_out[3] = c + 1;
                    return 1;
                }
            }
        }
    }

    return 0;
}


void confirmArrangement(int r[], int c[], int count) {
    for (int i = 0; i < count; i++)
        seats[r[i]][c[i]] = '*';
}
void chooseByUser() {
    int n;
    printf("請輸入要選幾個座位 (1~4)：");
    scanf("%d", &n);
    getchar();
    if (n < 1 || n > 4) {
        printf("輸入數量錯誤。\n");
        return;
    }

    int r[4], c[4];
    for (int i = 0; i < n; i++) {
        while (1) {
            printf("請輸入第 %d 個座位 (格式：列-行，例如 1-2)：", i + 1);
            fgets(input, sizeof(input), stdin);
            if (!isValidFormat(input, &r[i], &c[i]) || !isAvailable(r[i], c[i])) {
                printf("格式錯誤或座位已被佔用，請重試。\n");
                continue;
            }

            int repeated = 0;
            for (int j = 0; j < i; j++) {
                if (r[i] == r[j] && c[i] == c[j]) {
                    repeated = 1;
                    break;
                }
            }
            if (repeated) {
                printf("座位重複，請重試。\n");
                continue;
            }

            break;
        }
    }

    for (int i = 0; i < n; i++)
        seats[r[i]][c[i]] = '@';

    showSeats();
    waitForEnter();

    for (int i = 0; i < n; i++)
        seats[r[i]][c[i]] = '*';
}

int isValidFormat(const char *s, int *r, int *c) {
    int row, col;
    if (sscanf(s, "%d-%d", &row, &col) != 2)
        return 0;
    if (row < 1 || row > 9 || col < 1 || col > 9)
        return 0;

    *r = row - 1;
    *c = col - 1;
    return 1;
}

        printf("是否要繼續使用？(y/n)：");
        fgets(input, sizeof(input), stdin);
        char c = tolower(input[0]);

        if (c == 'y')
            return;
        else if (c == 'n') {
            printf("感謝使用，程式結束！\n");
            exit(0);
        } else {
            printf("輸入錯誤，請輸入 y 或 n。\n");
        }
    }
}
