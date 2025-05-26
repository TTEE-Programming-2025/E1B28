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

void display_grades() {
    clear_screen();
    if (student_count == 0) {
        printf("�|����J����ǥ͸�ơC\n");
    } else {
        printf("�m�W\t�Ǹ�\t\t�ƾ�\t���z\t�^��\t����\n");
        for (int i = 0; i < student_count; i++) {
            printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics,
                   students[i].english, students[i].average);
        }
    }
    printf("\n�����N���^�D���...\n");
    getchar(); getchar();
}

void search_grades() {
    clear_screen();
    if (student_count == 0) {
        printf("�|����J����ǥ͸�ơC\n");
    } else {
        char target[20];
        int found = 0;
        printf("�п�J���d�ߤ��ǥͩm�W�G");
        scanf("%s", target);
        for (int i = 0; i < student_count; i++) {
            if (strcmp(students[i].name, target) == 0) {
                printf("\n�m�W�G%s\n�Ǹ��G%s\n�ƾǡG%.1f\n���z�G%.1f\n�^��G%.1f\n�����G%.1f\n",
                       students[i].name, students[i].id,
                       students[i].math, students[i].physics,
                       students[i].english, students[i].average);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("�d�L���ǥ͡C\n");
        }
    }
    printf("\n�����N���^�D���...\n");
    getchar(); getchar();
}
void rank_grades() {
    clear_screen();
    if (student_count == 0) {
        printf("�|����J����ǥ͸�ơC\n");
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
        printf("�ƦW�G\n�W��\t�m�W\t�Ǹ�\t\t�������Z\n");
        for (int i = 0; i < student_count; i++) {
            printf("%d\t%s\t%s\t%.1f\n", i + 1, students[i].name, students[i].id, students[i].average);
        }
    }
    printf("\n�����N���^�D���...\n");
    getchar(); getchar();
}

void show_menu() {
    printf("------------[Grade System]------------\n");
    printf("| a. ��J�ǥͦ��Z                    |\n");
    printf("| b. ��ܩҦ����Z                    |\n");
    printf("| c. �d�߫��w�ǥ�                    |\n");
    printf("| d. �������Z�Ƨ�                    |\n");
    printf("| e. ���}�t��                        |\n");
    printf("--------------------------------------\n");
    printf("�п�ܥ\�� (a-e)�G");
}

