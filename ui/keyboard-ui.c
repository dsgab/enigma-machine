#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "keyboard-ui.h"
#include "general-use-ui.h"
#include "../file-operations.h"
#include "../strings.h"
#include "../input.h"
#include "../encryption.h"

char* keyboardLayoutRows[] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};    /* Array of strings containing the QWERTY keyboard layout rows */
unsigned char keyboardLayoutRowOffsets[] = {0, 2, 6};   /* Number of spaces in the beginning of each keyboard row */

void printKeyboardMenu(void)
{
    clearScreen();
    printKeyboard();
    printNewLine();
    printNewLine();
    printf("Encrypted word: %s\n", word);
    puts("Press space to write a new word.\nPress enter to write a new message.\nPress ESC to save and quit.");
}

void printKeyboard(void)
{
    for(int i = 0; i < 3; i++) printKeyboardRow(i);
}

void printKeyboardRow(int rowNumber)
{
    printSpaces(keyboardLayoutRowOffsets[rowNumber]);
    printKeyboardRowLetters(rowNumber);
    printNewLine();
}

void printKeyboardRowLetters(int rowNumber)
{
    for(int i = 0; keyboardLayoutRows[rowNumber][i] != '\0'; i++)
    {
        char letter = keyboardLayoutRows[rowNumber][i];
        if(i != 0) printSpaces(3);
        printKeyboardRowLetter(letter);
    }
}

void printKeyboardRowLetter(int asciiValue)
{
    if(tolower(asciiValue) == tolower(lastLetter)) printf(RED);
    printf("%c", asciiValue);
    printf(RESET_COLOR);
}

/*
"Q   W   E   R   T   Y   U   I   O   P\n"
"  A   S   D   F   G   H   J   K   L\n"
"      Z   X   C   V   B   N   M\n"
*/