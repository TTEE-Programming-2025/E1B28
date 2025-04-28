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
