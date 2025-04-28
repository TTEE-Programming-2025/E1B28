#include<stdio.h>
#include<stdlib.h>

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
