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
short secondRotorOffsetIn[26] = {0, 8, 1, 7, 14, 3, 11, 13, 15, 18, 1, 22, 10, 6, 24, 13, 0, 15, 7, 20, 21, 3, 9, 24, 16, 5};
short secondRotorOffsetOut[26] = {0, 8, 13, 25, 21, 17, 11, 4, 23, 18, 19, 25, 2, 6, 10, 5, 0, 15, 12, 20, 13, 2, 16, 11, 23, 19};
short thirdRotorOffsetIn[26] = {1, 2, 3, 4, 5, 6, 22, 8, 9, 10, 13, 10, 13, 0, 10, 15, 18, 5, 14, 7, 16, 17, 24, 21, 18, 15};
short thirdRotorOffsetOut[26] = {19, 25, 4, 24, 11, 23, 12, 22, 8, 21, 10, 20, 9, 0, 11, 18, 8, 17, 5, 16, 2, 16, 21, 13, 16, 13};
short lettersToReflect[26] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};
short firstRotorNotch = 17;
short secondRotorNotch = 5;
short thirdRotorNotch = 22;

char encryptLetter(char letter)
{
    currentEncryptedLetter = letter;
    rotateRotor(thirdRotor);
    goThroughRotors(thirdRotor, secondRotor, firstRotor);
    reflectLetter(currentEncryptedLetter);
    returnThroughRotors(firstRotor, secondRotor, thirdRotor);
    return currentEncryptedLetter;
}

void initializeRotors(void)
{
    initializeRotor(&firstRotor, firstRotorOffsetIn, firstRotorOffsetOut, NULL, firstRotorNotch);
    initializeRotor(&secondRotor, secondRotorOffsetIn, secondRotorOffsetOut, firstRotor, secondRotorNotch);
    initializeRotor(&thirdRotor, thirdRotorOffsetIn, thirdRotorOffsetOut, secondRotor, thirdRotorNotch);
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

void returnThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third)
{
    returnThroughRotor(first);
    returnThroughRotor(second);
    returnThroughRotor(third);
}

void goThroughRotor(ROTOR* rotor)
{
    changeEncryptedLetter(rotor->inLettersToAdvance[calculateLetterPosition(rotor->currentPosition, currentEncryptedLetter)]);
}

void returnThroughRotor(ROTOR* rotor)
{
    changeEncryptedLetter(rotor->outLettersToAdvance[calculateLetterPosition(rotor->currentPosition, currentEncryptedLetter)]);
}

short calculateLetterPosition(short rotorCurrentPosition, char encryptedLetter)
{
    return (rotorCurrentPosition + indexInAlphabet(encryptedLetter)) % LETTER_COUNT;
}

void changeEncryptedLetter(short offset)
{
    int letterValue = indexInAlphabet(currentEncryptedLetter);
    currentEncryptedLetter -= letterValue;
    letterValue += offset;
    letterValue %= LETTER_COUNT;
    currentEncryptedLetter += letterValue;
}

void reflectLetter(char letterToBeReflected)
{
    int letterValue = indexInAlphabet(letterToBeReflected);
    letterToBeReflected -= letterValue;
    letterValue = lettersToReflect[letterValue];
    letterToBeReflected += letterValue;
    currentEncryptedLetter = letterToBeReflected;
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

short getRotorCurrentPosition(ROTOR* rotor)
{
    return (rotor->currentPosition) + 1;
}