#include <stdio.h>
#include <stdlib.h>
#include "./ui/keyboard-ui.h"
#include "./ui/main-menu-ui.h"
#include "./ui/general-use-ui.h"
#include "file-operations.h"
#include "input.h"

int main(void)
{
    changeCursorVisibility(DISAPPEAR);
    openOutputFile();
    printMenu();
    clearScreen();
    while(1)
    {
        printKeyboardMenu();
        if(checkInput() == EXIT_LOOP) break;
    }
    changeCursorVisibility(REAPPEAR);
    clearScreen();
    closeOutputFile();
    return 0;
}