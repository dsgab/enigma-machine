#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"
#include "strings.h"

char currentEncryptedLetter;
ROTOR* firstRotor = NULL;
int firstRotorOffset[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

ROTOR* allocateRotor(void)
{
    return malloc(sizeof(ROTOR));
}

char encryptLetter(char letter)
{
    currentEncryptedLetter = letter;
    goThroughRotor(firstRotor);
    rotateRotor(firstRotor);
    return currentEncryptedLetter;
}

void initializeRotors(void)
{
    firstRotor = initializeRotor(firstRotorOffset, secondRotor, firstRotorNotch);
    secondRotor = initializeRotor(secondRotorOffset, thirdRotor, secondRotorNotch);
    thirdRotor = initializeRotor(thirdRotorOffset, NULL, thirdRotorNotch);
}

ROTOR* initializeRotor(short* rotorOffset, ROTOR* nextRotor, short notchPosition)
{
    ROTOR* rotor = allocateRotor();
    rotor->lettersToAdvance = rotorOffset;
    rotor->currentPosition = 0;
    rotor->nextRotor = nextRotor;
    rotor->notchPosition = notchPosition;
    return rotor;
}

void rotateRotor(ROTOR* rotor)
{
    rotor->currentPosition++;
    rotor->currentPosition %= 26;
}

void goThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third)
{
    goThroughRotor(first);
    goThroughRotor(second);
    goThroughRotor(third);
}

void goThroughRotor(ROTOR* rotor)
{
    changeEncryptedLetter(rotor->lettersToAdvance[rotor->currentPosition]);
}

void changeEncryptedLetter(short offset)
{
    int letterValue = indexInAlphabet(currentEncryptedLetter);
    currentEncryptedLetter -= letterValue;
    letterValue += offset;
    letterValue %= 26;
    currentEncryptedLetter += letterValue;
}