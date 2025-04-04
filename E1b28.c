#include <stdio.h>
#include <stdlib.h> 

int main() {
    /******************** 步驟1：顯示歡迎畫面 ********************/
    printf("\n\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    printf("hello\n");
    printf("*程式設計作業1*\n");
    printf("\n");
    printf("班級：E1b\n");
    printf("座號：28\n");
    printf("姓名：陳可晴\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("請按任意鍵繼續... \n");
    printf("* *\n");
    printf("**************************************************\n");
    
    system("PAUSE");
    system("CLS");

    /******************** 步驟2：密碼驗證 ********************/
    int password, correctPassword = 2024;
    int attempts = 3;
    
    while (attempts > 0) {
        printf("\n\n");
        printf("**************************************************\n");
        printf("* 密碼驗證系統 *\n");
        printf("* *\n");
        printf("* 請輸入4位數密碼 (剩餘嘗試次數: %d) *\n", attempts);
        printf("* 預設密碼: 2024 *\n");
        printf("* *\n");
        printf("**************************************************\n");
        printf("\n請輸入密碼: ");
        
        scanf("%d", &password);
        fflush(stdin); 
        
        if (password == correctPassword) {
            printf("\n密碼正確！歡迎使用本系統。\n");
            system("PAUSE");
            system("CLS");
            break; 
        } else {
            attempts--;
            printf("%c", '\a'); 
            printf("\n密碼錯誤！");
            
            if (attempts > 0) {
                printf("請重新輸入。\n");
            } else {
                printf("已達最大嘗試次數，系統將關閉。\n");
                system("PAUSE");
                return 0; 
            }
        }
    }

    /******************** 步驟3：顯示主選單 ********************/
    printf("\n\n");
    printf("**************************************************\n");
    printf("* 主選單 *\n");
    printf("* *\n");
    printf("* 請輸入一個字元，系統將判斷其類別: *\n");
    printf("* *\n");
    printf("* 'A'...'Z' : Uppercase *\n");
    printf("* 'a'...'z' : Lowercase *\n");
    printf("* '0'...'9' : Digit (數字) *\n");
    printf("* 其他 : 顯示您的姓名與座號 *\n");
    printf("* *\n");
    printf("**************************************************\n");
    printf("\n");

    /******************** 步驟4：字元分類 ********************/
    char input;
    printf("請輸入一個字元: ");
    fflush(stdin);
    scanf("%c", &input);
    
    printf("\n");
    printf("==================================================\n");
    if (input >= 'A' && input <= 'Z') {
        printf(" 您輸入的是: Uppercase \n");
    } else if (input >= 'a' && input <= 'z') {
        printf(" 您輸入的是: Lowercase \n");
    } else if (input >= '0' && input <= '9') {
        printf(" 您輸入的是: Digit\n");
    } else {
        printf(" E1050 班級E1B 座號:28 姓名:陳可晴\n"); 
    }
    printf("==================================================\n");

    printf("\n程式執行完畢，按任意鍵結束...\n");
    system("PAUSE");
    
    return 0;
}
