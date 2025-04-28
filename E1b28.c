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

void displayMainMenu() {
    printf("========================================\n");
    printf("|          主選單                     |\n");
    printf("|                                      |\n");
    printf("|  a. 畫出直角三角形                  |\n");
    printf("|  b. 顯示乘法表                      |\n");
    printf("|  c. 結束                            |\n");
    printf("|                                      |\n");
    printf("========================================\n");
}


void drawTriangle() {
    clearScreen();
    char inputChar;
    
    while (1) {
        printf("請輸入一個a到n的字元: ");
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
            printf("錯誤！請輸入a到n之間的字元！\n");
        }
    }
    
    
}


void showMultiplicationTable() {
    clearScreen();
    int n;
    
    while (1) {
        printf("請輸入一個1到9的整數: ");
        scanf("%d", &n);
        
        if (n >= 1 && n <= 9) {
            printf("\n  %d x %d 乘法表\n", n, n);
            printf("==================\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%d x %d = %-2d  ", i, j, i * j);
                }
                printf("\n");
            }
            break;
        } else {
            printf("錯誤！請輸入1到9之間的整數！\n");
        }
    }
    
    
}


void clearScreen() {
    system("cls");
   
}
