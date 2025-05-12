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
void printWelcome() {
    for (int i = 0; i < 20; i++) {
        printf("=== �w��ϥέq��t�� ===\n");
    }
}


int checkPassword() {
    int attempt = 0, user_input;

    while (attempt < MAX_ATTEMPTS) {
        printf("�п�J�|��ƱK�X�G");
        scanf("%d", &user_input);
        getchar(); // �Y������
        if (user_input == PASSWORD) {
            printf("�K�X���T�A�w��i�J�t�ΡI\n");
            return 1;
        } else {
            printf("�K�X���~�I\n");
            attempt++;
        }
    }
    return 0;
}

void showMenu() {
    printf("\n----------[�q��t��]----------\n");
    printf("|  a. �d�ݥi�ήy��            |\n");
    printf("|  b. �t�Φ۰ʦw�Ʈy��        |\n");
    printf("|  c. �ۦ��ܮy��            |\n");
    printf("|  d. ���}�t��                |\n");
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
    printf("�� Enter ��^��D���...");
    getchar();
}


void arrangeSeats() {
    int count;
    int r[4], c[4];

    printf("�аݻݭn�X�Ӯy�� (1~4)�G");
    scanf("%d", &count);
    getchar();
    if (count < 1 || count > 4) {
        printf("��J�H�ƵL�ġC\n");
        return;
    }

    if (!findConsecutiveSeats(count, r, c)) {
        printf("�䤣��X�A���s��y��C\n");
        return;
    }

