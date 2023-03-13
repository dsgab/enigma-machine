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
short firstRotorOffsetIn[26] = {4, 9, 10, 2, 7, 1, 23, 9, 13, 16, 3, 8, 2, 9, 10, 18, 7, 3, 0, 22, 6, 13, 5, 20, 4, 10};
short firstRotorOffsetOut[26] = {20, 21, 22, 3, 22, 24, 25, 8, 13, 16, 17, 19, 16, 23, 24, 4, 17, 6, 0, 18, 23, 13, 17, 19, 16, 10};
short secondRotorOffset[26] = {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4};
short thirdRotorOffset[26] = {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14};
short lettersToReflect[26] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};
short firstRotorNotch = 0;
short secondRotorNotch = 0;
short thirdRotorNotch = 0;

char encryptLetter(char letter)
{
    currentEncryptedLetter = letter;
    goThroughRotor(firstRotor);
    currentEncryptedLetter = reflectLetter(currentEncryptedLetter);
    returnThroughRotor(firstRotor);
    rotateRotor(firstRotor);
    return currentEncryptedLetter;
}

void initializeRotors(void)
{
    initializeRotor(&thirdRotor, thirdRotorOffset, NULL, NULL, thirdRotorNotch);
    initializeRotor(&secondRotor, secondRotorOffset, NULL, thirdRotor, secondRotorNotch);
    initializeRotor(&firstRotor, firstRotorOffsetIn, firstRotorOffsetOut, secondRotor, firstRotorNotch);
}

void initializeRotor(ROTOR** rotor, short* rotorOffsetIn, short* rotorOffsetOut, ROTOR* nextRotor, short notchPosition)
{
    ROTOR* temporaryRotor = allocateRotor();
    temporaryRotor->inLettersToAdvance = rotorOffsetIn;
    temporaryRotor->outLettersToAdvance = rotorOffsetOut;
    temporaryRotor->currentPosition = 0;
    temporaryRotor->nextRotor = nextRotor;
    temporaryRotor->notchPosition = notchPosition;
    *rotor = temporaryRotor;
}

void rotateRotor(ROTOR* rotor)
{
    rotor->currentPosition++;
    rotor->currentPosition %= 26;
    if(rotor->currentPosition == rotor->notchPosition && rotor->nextRotor != NULL) rotateRotor(rotor->nextRotor);
}

void goThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third)
{
    goThroughRotor(first);
    goThroughRotor(second);
    goThroughRotor(third);
}

void returnThroughRotor(ROTOR* rotor)
{
    changeEncryptedLetter(rotor->outLettersToAdvance[calculateLetterPosition(rotor->currentPosition, currentEncryptedLetter)]);
}

void goThroughRotor(ROTOR* rotor)
{
    changeEncryptedLetter(rotor->inLettersToAdvance[calculateLetterPosition(rotor->currentPosition, currentEncryptedLetter)]);
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

char reflectLetter(char letterToBeReflected)
{
    int letterValue = indexInAlphabet(letterToBeReflected);
    letterToBeReflected -= letterValue;
    letterValue = lettersToReflect[letterValue];
    return letterToBeReflected += letterValue;
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

short rotorCurrentPosition(ROTOR* rotor)
{
    return (rotor->currentPosition) + 1;
}