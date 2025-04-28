#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 


void displayWelcomeScreen();
int checkPassword();
void displayMainMenu();
void drawTriangle();
void showMultiplicationTable();
void clearScreen();

int main() {
 
    if (!checkPassword()) {
        return 0;  
    }
    

    while (1) {
        displayMainMenu();
        char choice;
        printf("�п�J�z�����: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'a':
            case 'A':
                drawTriangle();
                break;
            case 'b':
            case 'B':
                showMultiplicationTable();
                break;
            case 'c':
            case 'C':
                while (1) {
                    printf("Continue? (y/n): ");
                    char continueChoice;
                    scanf(" %c", &continueChoice);
                    
                    if (continueChoice == 'n' || continueChoice == 'N') {
                        printf("�{�������A�P�¨ϥΡI\n");
                        return 0;
                    } else if (continueChoice == 'y' || continueChoice == 'Y') {
                        clearScreen();
                        break;  
                    } else {
                        printf("���~��J�A�Э��s��J�I\n");
                    }
                }
                break;
            default:
                printf("�L�Ī���ܡA�Э��s��J�I\n");
                system("pause");
                clearScreen();
        }
    }
    
    return 0;
}

void displayWelcomeScreen() {
    printf("========================================\n");
    printf("|                                      |\n");
    printf("|      �w��ϥε{���]�p�@�~�t��        |\n");
    printf("|                                      |\n");
    printf("|          �@��:   ���i��              |\n");
    printf("|          ���: 2024/04/29            |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("========================================\n");
    printf("\n����: �w�]�K�X�O 2025\n");
}


int checkPassword() {
    int password = 2025;
    int attempts = 0;
    int input;
    
    while (attempts < 3) {
        displayWelcomeScreen();
        printf("�п�J4��ƱK�X (�Ѿl���զ���: %d): ", 3 - attempts);
        scanf("%d", &input);
        
        if (input == password) {
            clearScreen();
            return 1;
        } else {
            attempts++;
            printf("�K�X���~�I\n");
            if (attempts < 3) {
                system("pause");
                clearScreen();
            }
        }
    }
    

    printf("\nĵ�i�I�z�w�s��T����J���~�K�X�I\n");
    printf("�t�αN�۰�����...\n");
    system("pause");
    return 0;
}

void displayMainMenu() {
    printf("========================================\n");
    printf("|          �D���                     |\n");
    printf("|                                      |\n");
    printf("|  a. �e�X�����T����                  |\n");
    printf("|  b. ��ܭ��k��                      |\n");
    printf("|  c. ����                            |\n");
    printf("|                                      |\n");
    printf("========================================\n");
}


void drawTriangle() {
    clearScreen();
    char inputChar;
    
    while (1) {
        printf("�п�J�@��a��n���r��: ");
        scanf(" %c", &inputChar);
        
        if (inputChar >= 'a' && inputChar <= 'n') {
         
            int rows = inputChar - 'a' + 1;
            printf("\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j <= i; j++) {
                    printf("%c ", 'a' + j);
                }
                printf("\n");
            }
            break;
        } else if (inputChar >= 'A' && inputChar <= 'N') {
           
            int rows = inputChar - 'A' + 1;
            printf("\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j <= i; j++) {
                    printf("%c ", 'A' + j);
                }
                printf("\n");
            }
            break;
        } else {
            printf("���~�I�п�Ja��n�������r���I\n");
        }
    }
    
    
}


void showMultiplicationTable() {
    clearScreen();
    int n;
    
    while (1) {
        printf("�п�J�@��1��9�����: ");
        scanf("%d", &n);
        
        if (n >= 1 && n <= 9) {
            printf("\n  %d x %d ���k��\n", n, n);
            printf("==================\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%d x %d = %-2d  ", i, j, i * j);
                }
                printf("\n");
            }
            break;
        } else {
            printf("���~�I�п�J1��9��������ơI\n");
        }
    }
    
    
}


void clearScreen() {
    system("cls");
   
}
