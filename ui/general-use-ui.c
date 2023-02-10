#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "general-use-ui.h"

void printNewLine(void)
{
    putchar('\n');
}

void printSpaces(int numberOfSpaces)
{
    for(int i = 0; i < numberOfSpaces; i++) putchar(' ');
}

void clearScreen(void)
{
    system("clear");
}

void changeCursorVisibility(enum cursorState state)
{
    switch(state)
    {
        case DISAPPEAR:
            system("echo -e \"\\e]12;black\\a\"");
            break;
        case REAPPEAR:
            system("echo -e \"\\e]12;white\\a\"");
            break;
    }
}

void changeLetterVisibility(enum letterVisibility visibility)
{
    switch(visibility)
    {
        case INVISIBLE:
            printf(BLACK);
            break;
        case VISIBLE:
            printf(RESET_COLOR);
            break;
    }
}