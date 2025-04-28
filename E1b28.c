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
        printf("請輸入您的選擇: ");
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
                        printf("程式結束，感謝使用！\n");
                        return 0;
                    } else if (continueChoice == 'y' || continueChoice == 'Y') {
                        clearScreen();
                        break;  
                    } else {
                        printf("錯誤輸入，請重新輸入！\n");
                    }
                }
                break;
            default:
                printf("無效的選擇，請重新輸入！\n");
                system("pause");
                clearScreen();
        }
    }
    
    return 0;
}
void displayWelcomeScreen() {
    printf("========================================\n");
    printf("|                                      |\n");
    printf("|      歡迎使用程式設計作業系統        |\n");
    printf("|                                      |\n");
    printf("|          作者:   陳可晴              |\n");
    printf("|          日期: 2024/04/29            |\n");
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
    printf("\n提示: 預設密碼是 2025\n");
}


int checkPassword() {
    int password = 2025;
    int attempts = 0;
    int input;
    
    while (attempts < 3) {
        displayWelcomeScreen();
        printf("請輸入4位數密碼 (剩餘嘗試次數: %d): ", 3 - attempts);
        scanf("%d", &input);
        
        if (input == password) {
            clearScreen();
            return 1;
        } else {
            attempts++;
            printf("密碼錯誤！\n");
            if (attempts < 3) {
                system("pause");
                clearScreen();
            }
        }
    }
    

    printf("\n警告！您已連續三次輸入錯誤密碼！\n");
    printf("系統將自動關閉...\n");
    system("pause");
    return 0;
}
