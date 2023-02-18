#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"
#include "strings.h"

char currentEncryptedLetter;
ROTOR* firstRotor = NULL;
ROTOR* secondRotor = NULL;
ROTOR* thirdRotor = NULL;
short firstRotorOffset[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
short secondRotorOffset[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
short thirdRotorOffset[26] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
short firstRotorNotch = 0;
short secondRotorNotch = 0;
short thirdRotorNotch = 0;

char encryptLetter(char letter)
{
    currentEncryptedLetter = letter;
    goThroughRotor(firstRotor);
    rotateRotor(firstRotor);
    return currentEncryptedLetter;
}

void initializeRotors(void)
{
    initializeRotor(&firstRotor, firstRotorOffset, secondRotor, firstRotorNotch);
    initializeRotor(&secondRotor, secondRotorOffset, thirdRotor, secondRotorNotch);
    initializeRotor(&thirdRotor, thirdRotorOffset, NULL, thirdRotorNotch);
}

void initializeRotor(ROTOR** rotor, short* rotorOffset, ROTOR* nextRotor, short notchPosition)
{
    ROTOR* temporaryRotor = allocateRotor();
    temporaryRotor->lettersToAdvance = rotorOffset;
    temporaryRotor->currentPosition = 0;
    temporaryRotor->nextRotor = nextRotor;
    temporaryRotor->notchPosition = notchPosition;
    *rotor = temporaryRotor;
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
    changeEncryptedLetter(rotor->lettersToAdvance[(rotor->currentPosition + indexInAlphabet(currentEncryptedLetter))%26]);
}

void changeEncryptedLetter(short offset)
{
    int letterValue = indexInAlphabet(currentEncryptedLetter);
    currentEncryptedLetter -= letterValue;
    letterValue += offset;
    letterValue %= 26;
    currentEncryptedLetter += letterValue;
}

ROTOR* allocateRotor(void)
{
    return malloc(sizeof(ROTOR));
}