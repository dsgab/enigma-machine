#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"
#include "strings.h"

const int LETTER_COUNT = 'Z' - 'A' + 1;
char currentEncryptedLetter;
ROTOR* firstRotor = NULL;
ROTOR* secondRotor = NULL;
ROTOR* thirdRotor = NULL;
short firstRotorOffset[26] = {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9};
short secondRotorOffset[26] = {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4};
short thirdRotorOffset[26] = {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14};
short firstRotorNotch = 0;
short secondRotorNotch = 0;
short thirdRotorNotch = 0;

char encryptLetter(char letter)
{
    currentEncryptedLetter = letter;
    goThroughRotor(firstRotor);
    goThroughRotor(secondRotor);
    goThroughRotor(thirdRotor);
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
    changeEncryptedLetter(rotor->lettersToAdvance[calculateLetterPosition(rotor->currentPosition, currentEncryptedLetter)]);
}

short calculateLetterPosition(short rotorCurrentPosition, char inputLetter)
{
    return (rotorCurrentPosition + indexInAlphabet(inputLetter)) % LETTER_COUNT;
}

void changeEncryptedLetter(short offset)
{
    int letterValue = indexInAlphabet(currentEncryptedLetter);
    currentEncryptedLetter -= letterValue;
    letterValue += offset;
    letterValue %= LETTER_COUNT;
    currentEncryptedLetter += letterValue;
}

ROTOR* allocateRotor(void)
{
    return malloc(sizeof(ROTOR));
}

void freeRotors(void)
{
    free(firstRotor);
    free(secondRotor);
    free(thirdRotor);
}