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
short lettersToReflect[ALPHABET_SIZE] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};

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
    rotor->currentPosition %= ALPHABET_SIZE;
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
    return (rotorCurrentPosition + indexInAlphabet(encryptedLetter)) % ALPHABET_SIZE;
}

void changeEncryptedLetter(short offset)
{
    int letterValue = indexInAlphabet(currentEncryptedLetter);
    currentEncryptedLetter -= letterValue;
    letterValue += offset;
    letterValue %= ALPHABET_SIZE;
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