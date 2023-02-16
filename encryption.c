#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"

ROTOR* firstRotor = NULL;
int firstRotorOffset[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

ROTOR* allocateRotor(void)
{
    return malloc(sizeof(ROTOR));
}

char encryptLetter(char letter)
{
    bool isLetterUpper = isupper(letter);
    letter -= isLetterUpper ? 'A' : 'a';
    letter += firstRotor->lettersToAdvance[firstRotor->currentPosition];
    rotateRotor(firstRotor);
    letter %= 26;
    letter += isLetterUpper ? 'A' : 'a';
    return letter;
}

void initializeRotors(void)
{
    firstRotor = allocateRotor();
    for(int i = 0; i < 26; i++) firstRotor->lettersToAdvance[i] = firstRotorOffset[i];
    firstRotor->currentPosition = 0;
}

void rotateRotor(ROTOR* rotor)
{
    rotor->currentPosition++;
    rotor->currentPosition %= 26;
}