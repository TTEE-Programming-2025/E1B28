#include <stdio.h>
#include <stdlib.h> 

int main() {
    /******************** �B�J1�G����w��e�� ********************/
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
    printf("*�{���]�p�@�~1*\n");
    printf("\n");
    printf("�Z�šGE1b\n");
    printf("�y���G28\n");
    printf("�m�W�G���i��\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("�Ы����N���~��... \n");
    printf("* *\n");
    printf("**************************************************\n");
    
    system("PAUSE");
    system("CLS");
    /******************** �B�J2�G�K�X���� ********************/
    int password, correctPassword = 2024;
    int attempts = 3;
    
    while (attempts > 0) {
        printf("\n\n");
        printf("**************************************************\n");
        printf("* �K�X���Ҩt�� *\n");
        printf("* *\n");
        printf("* �п�J4��ƱK�X (�Ѿl���զ���: %d) *\n", attempts);
        printf("* �w�]�K�X: 2024 *\n");
        printf("* *\n");
        printf("**************************************************\n");
        printf("\n�п�J�K�X: ");
        
        scanf("%d", &password);
        fflush(stdin); 
        
        if (password == correctPassword) {
            printf("\n�K�X���T�I�w��ϥΥ��t�ΡC\n");
            system("PAUSE");
            system("CLS");
            break; 
        } else {
            attempts--;
            printf("%c", '\a'); 
            printf("\n�K�X���~�I");
            
            if (attempts > 0) {
                printf("�Э��s��J�C\n");
            } else {
                printf("�w�F�̤j���զ��ơA�t�αN�����C\n");
                system("PAUSE");
                return 0; 
            }
        }
    }

    
    return 0;
}
