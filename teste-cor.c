#include <stdio.h>
#include <stdlib.h>

#define REINICIAR "\033[0m"
#define PRETO "\033[30m"
#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define AZUL "\033[34m"
#define ROXO "\033[35m"
#define CIANO "\033[36m"
#define NEGRITO "\033[1;37m"
#define SUMIR_CURSOR "echo -e \"\\e]12;black\\a\""
#define VOLTAR_CURSOR "echo -e \"\\e]12;white\\a\""

void printMenu(void);
char getInput(void);

int main(void)
{
    system(SUMIR_CURSOR);
    while(1)
    {
        printMenu();
    }
    return 0;
}

void printMenu(void)
{
    int option;
    system("clear");
    printf("Escolha uma cor para ser aplicada a essa frase!\n");
    option = getInput();
    switch(option)
    {
        case 48:
            printf(REINICIAR);
            break;
        case 49:
            printf(PRETO);
            break;
        case 50:
            printf(VERMELHO);
            break;
        case 51:
            printf(VERDE);
            break;
        case 52:
            printf(AMARELO);
            break;
        case 53:
            printf(AZUL);
            break;
        case 54:
            printf(ROXO);
            break;
        case 55:
            printf(CIANO);
            break;
        case 57:
            system(VOLTAR_CURSOR);
            exit(0);
        default:
            break;
    }
    if(option == 13)
    {
        system(VOLTAR_CURSOR);
        exit(0);
    }
}

char getInput(void)
{
    char answer = 'a';
    system("/bin/stty raw");
    answer = getc(stdin);
    system("/bin/stty cooked");
    return answer;
}