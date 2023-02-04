#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "file-operations.h"
#include "input.h"

int main(void)
{
    changeCursorVisibility(DISAPPEAR);
    initializeOutputFile();
    while(1)
    {
        printMenu();
        if(checkInput() == 1) break;
    }
    changeCursorVisibility(REAPPEAR);
    clearScreen();
    closeOutputFile();
    return 0;
}