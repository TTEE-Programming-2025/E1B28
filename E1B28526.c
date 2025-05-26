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

void display_grades() {
    clear_screen();
    if (student_count == 0) {
        printf("尚未輸入任何學生資料。\n");
    } else {
        printf("姓名\t學號\t\t數學\t物理\t英文\t平均\n");
        for (int i = 0; i < student_count; i++) {
            printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics,
                   students[i].english, students[i].average);
        }
    }
    printf("\n按任意鍵返回主選單...\n");
    getchar(); getchar();
}

void search_grades() {
    clear_screen();
    if (student_count == 0) {
        printf("尚未輸入任何學生資料。\n");
    } else {
        char target[20];
        int found = 0;
        printf("請輸入欲查詢之學生姓名：");
        scanf("%s", target);
        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].name, target) == 0) {
                printf("\n姓名：%s\n學號：%s\n數學：%.1f\n物理：%.1f\n英文：%.1f\n平均：%.1f\n",
                       students[i].name, students[i].id,
                       students[i].math, students[i].physics,
                       students[i].english, students[i].average);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("查無此學生。\n");
        }
    }
    printf("\n按任意鍵返回主選單...\n");
    getchar(); getchar();
}
void rank_grades() {
    clear_screen();
    if (student_count == 0) {
        printf("尚未輸入任何學生資料。\n");
    } else {
        Student temp;
        for (int i = 0; i < student_count - 1; i++) {
            for (int j = i + 1; j < student_count; j++) {
                if (students[i].average < students[j].average) {
                    temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
        printf("排名：\n名次\t姓名\t學號\t\t平均成績\n");
        for (int i = 0; i < student_count; i++) {
            printf("%d\t%s\t%s\t%.1f\n", i + 1, students[i].name, students[i].id, students[i].average);
        }
    }
    printf("\n按任意鍵返回主選單...\n");
    getchar(); getchar();
}

void show_menu() {
    printf("------------[Grade System]------------\n");
    printf("| a. 輸入學生成績                    |\n");
    printf("| b. 顯示所有成績                    |\n");
    printf("| c. 查詢指定學生                    |\n");
    printf("| d. 平均成績排序                    |\n");
    printf("| e. 離開系統                        |\n");
    printf("--------------------------------------\n");
    printf("請選擇功能 (a-e)：");
}

