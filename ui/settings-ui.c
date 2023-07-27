#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "general-use-ui.h"
#include "settings-ui.h"
#include "../encryption.h"

void printSettingsScreen(void)
{
    clearScreen();
    puts("Settings");
    printNewLine();
    puts("Choose an option:");
    printNewLine();
    puts("1. Set rotors.");
    printNewLine();
    puts("2. Set plugboard.");
    printNewLine();
    puts("3. Change keyboard light color.");
}