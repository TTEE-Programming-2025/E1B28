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
float calc_avg(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

void enter_grades() {
    clear_screen();
    printf("請輸入學生人數 (5~10)：");
    scanf("%d", &student_count);
    if (student_count < 5 || student_count > 10) {
        printf("人數超出範圍。\n");
        student_count = 0;
        printf("\n按任意鍵返回主選單...\n");
        getchar(); getchar();
        return;
    }
    for (int i = 0; i < student_count; i++) {
        printf("\n第 %d 位學生：\n", i + 1);
        printf("姓名：");
        scanf("%s", students[i].name);
        printf("學號（6位數）：");
        scanf("%s", students[i].id);
        printf("數學成績 (0~100)：");
        scanf("%f", &students[i].math);
        printf("物理成績 (0~100)：");
        scanf("%f", &students[i].physics);
        printf("英文成績 (0~100)：");
        scanf("%f", &students[i].english);
        students[i].average = calc_avg(students[i].math, students[i].physics, students[i].english);
    }
    printf("\n資料輸入完成，按任意鍵返回主選單...\n");
    getchar(); getchar();
}
