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
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &input);
        if (input == PASSWORD) return 1;
        else {
            printf("�K�X���~�A�ЦA�դ@���C\n");
            tries++;
            getchar(); getchar(); 
        }
    }
    printf("���~���ƹL�h�A�{�������C\n");
    return 0;
}
