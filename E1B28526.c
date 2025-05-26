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
float calc_avg(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

void enter_grades() {
    clear_screen();
    printf("�п�J�ǥͤH�� (5~10)�G");
    scanf("%d", &student_count);
    if (student_count < 5 || student_count > 10) {
        printf("�H�ƶW�X�d��C\n");
        student_count = 0;
        printf("\n�����N���^�D���...\n");
        getchar(); getchar();
        return;
    }
    for (int i = 0; i < student_count; i++) {
        printf("\n�� %d ��ǥ͡G\n", i + 1);
        printf("�m�W�G");
        scanf("%s", students[i].name);
        printf("�Ǹ��]6��ơ^�G");
        scanf("%s", students[i].id);
        printf("�ƾǦ��Z (0~100)�G");
        scanf("%f", &students[i].math);
        printf("���z���Z (0~100)�G");
        scanf("%f", &students[i].physics);
        printf("�^�妨�Z (0~100)�G");
        scanf("%f", &students[i].english);
        students[i].average = calc_avg(students[i].math, students[i].physics, students[i].english);
    }
    printf("\n��ƿ�J�����A�����N���^�D���...\n");
    getchar(); getchar();
}
