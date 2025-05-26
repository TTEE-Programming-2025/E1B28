#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define PASSWORD 2025

typedef struct {
    char name[20];
    char id[10];
    float math, physics, english;
    float average;
} Student;

Student students[MAX];
int student_count = 0;
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int login() {
    int input, tries = 0;
    while (tries < 3) {
        clear_screen();
        printf("請輸入4位數密碼：");
        scanf("%d", &input);
        if (input == PASSWORD) return 1;
        else {
            printf("密碼錯誤，請再試一次。\n");
            tries++;
            getchar(); getchar(); 
        }
    }
    printf("錯誤次數過多，程式結束。\n");
    return 0;
}
