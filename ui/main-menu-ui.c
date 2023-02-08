#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "main-menu-ui.h"
#include "keyboard-ui.h"
#include "general-use-ui.h"
#include "../strings.h"
#include "../input.h"
#include "../file-operations.h"

void printMainMenu(void)
{
    clearScreen();
    printAsciiArt();
    printNewLine();
    puts("Choose an option:\n1. Encrypt or decrypt a message.\n2. Settings.\n3. Exit.");
}

void printAsciiArt(void)
{
    puts("ENIGMA");
}