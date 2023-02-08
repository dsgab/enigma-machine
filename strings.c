#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "strings.h"
#include "./ui/keyboard-ui.h"
#include "input.h"

bool isStringEmpty(char* string)
{
    return string[0] == '\0' ? true : false;
}

bool isCharacterLetter(char character)
{
    if(tolower(character) >= 'a' && tolower(character) <= 'z') return 1;
    return 0;
}

unsigned char indexInAlphabet(char letter)
{
    letter = toupper(letter);
    return letter - 'A';
}

void concatenateCharacter(char* string, char character)
{
    char tempCharacter[2];
    tempCharacter[0] = character;
    tempCharacter[1] = '\0';
    strcat(string, tempCharacter);
}

void deleteStringLastCharacter(char* string)    /* Currently not being used */
{
    if(isStringEmpty(string)) return;
    string[strlen(string)-1] = '\0';
}