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
    for (int i = 0; i < count; i++)
        seats[r[i]][c[i]] = '@';

    showSeats();
    printf("�O�_���N���w�ơH(y/n)�G");
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
    printf("�п�J�n��X�Ӯy�� (1~4)�G");
    scanf("%d", &n);
    getchar();
    if (n < 1 || n > 4) {
        printf("��J�ƶq���~�C\n");
        return;
    }

    int r[4], c[4];
    for (int i = 0; i < n; i++) {
        while (1) {
            printf("�п�J�� %d �Ӯy�� (�榡�G�C-��A�Ҧp 1-2)�G", i + 1);
            fgets(input, sizeof(input), stdin);
            if (!isValidFormat(input, &r[i], &c[i]) || !isAvailable(r[i], c[i])) {
                printf("�榡���~�ήy��w�Q���ΡA�Э��աC\n");
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
                printf("�y�쭫�ơA�Э��աC\n");
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

        printf("�O�_�n�~��ϥΡH(y/n)�G");
        fgets(input, sizeof(input), stdin);
        char c = tolower(input[0]);

        if (c == 'y')
            return;
        else if (c == 'n') {
            printf("�P�¨ϥΡA�{�������I\n");
            exit(0);
        } else {
            printf("��J���~�A�п�J y �� n�C\n");
        }
    }
}
