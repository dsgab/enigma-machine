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
    puts("3. Change keyboard lights color.");
    printNewLine();
    puts("Press ESC to return.");
}

void printRotorSettingsScreen(void)
{
    clearScreen();
    puts("Settings / Rotors");
    printNewLine();
    printf("Current rotors: %s, %s and %s\n", firstRotor->name, secondRotor->name, thirdRotor->name);
    printNewLine();
    puts("Press ESC to return.");
}

void printPlugboardSettingsScreen(void)
{
    clearScreen();
    puts("Settings / Plugboard");
    printNewLine();
    printf("Current plugboard settings: \n");
    printNewLine();
    puts("Type 1 to change the plugboard.");
    printNewLine();
    puts("Press ESC to return.");
}

void printKeyboardSettingsScreen(void)
{
    clearScreen();
    puts("Settings / Keyboard lights");
    printNewLine();
    printf("Current color: \n");
    printNewLine();
    puts("1. Red.");
    printNewLine();
    puts("2. Yellow.");
    printNewLine();
    puts("3. Blue.");
    printNewLine();
    puts("4. Green.");
    printNewLine();
    puts("Press ESC to return.");
}