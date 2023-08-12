#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./ui/keyboard-ui.h"
#include "./ui/main-menu-ui.h"
#include "./ui/general-use-ui.h"
#include "file-operations.h"
#include "input.h"
#include "encryption.h"

int main(void)
{
    changeCursorVisibility(DISAPPEAR);
    openOutputFile();
    initializeRotors();
    debugFile = fopen(debugFileName, "w");
    while(true)
    {
        printMainMenu();
        if(checkMainMenuInput() == EXIT_MAIN_MENU) break;
    }
    freeRotors();
    changeCursorVisibility(REAPPEAR);
    clearScreen();
    closeOutputFile();
    return 0;
}