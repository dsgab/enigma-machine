#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"
#include "strings.h"
#include "file-operations.h"

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
    char **rotorsInfo = getCurrentRotorsInfo();
    initializeRotor(&firstRotor, rotorsInfo[0], NULL);
    initializeRotor(&secondRotor, rotorsInfo[1], firstRotor);
    initializeRotor(&thirdRotor, rotorsInfo[2], secondRotor);
}

void initializeRotor(ROTOR** rotor, char* rotorInfo, ROTOR* nextRotor)
{
    ROTOR* temporaryRotor = allocateRotor();
    setRotor(temporaryRotor, getName(rotorInfo), getLetters(rotorInfo), getNotch(rotorInfo));
    temporaryRotor->nextRotor = nextRotor;
    *rotor = temporaryRotor;
}

void setRotor(ROTOR* rotor, char* name, char* letters, short notchPosition)
{
    rotor->name = name;
    rotor->inLettersToAdvance = calculateOffsetIn(letters);
    rotor->outLettersToAdvance = calculateOffsetOut(letters);
    rotor->currentPosition = 0;
    rotor->notchPosition = notchPosition;
}

char* getName(char* rotorInfo)
{
    char *position, *name = NULL;
    int nameSize = 0;
    if(!rotorInfo) return NULL;
    rotorInfo += 5;
    position = rotorInfo;
    while(*position != ' ') position++;
    nameSize = position - rotorInfo;
    name = (char*) malloc(nameSize * sizeof(char));
    strncpy(name, rotorInfo, nameSize);
    return name;
}

short getNotch(char* rotorInfo)
{
    short notch;
    char* tempNotch = (char*) malloc(2 * sizeof(char));
    strncpy(tempNotch, rotorInfo+2, 2);
    notch = atoi(tempNotch);
    return notch;
}

char* getLetters(char* rotorInfo)
{
    char *startPosition = rotorInfo + 5, *letters = (char*) malloc(ALPHABET_SIZE * sizeof(char));
    while(*startPosition != ' ') startPosition++;
    startPosition++;
    strncpy(letters, startPosition, ALPHABET_SIZE);
    return letters;
}

short* calculateOffsetIn(char* rotorCharacters)
{
    if(strlen(rotorCharacters) != ALPHABET_SIZE) return NULL;
    char reference[ALPHABET_SIZE+1] = "abcdefghijklmnopqrstuvwxyz";
    if(strlen(reference) != ALPHABET_SIZE) printf("Reference size is wrong. Size: %ld\n", strlen(reference));
    short* offset = malloc(sizeof(short) * ALPHABET_SIZE);
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        char currentLetter = tolower(rotorCharacters[i]);
        short difference = currentLetter - reference[i];
        offset[i] = difference >= 0 ? difference : difference + 26;
    }
    return offset;
}

short* calculateOffsetOut(char* rotorCharacters)
{
    if(strlen(rotorCharacters) != ALPHABET_SIZE) return NULL;
    char reference[ALPHABET_SIZE+1] = "abcdefghijklmnopqrstuvwxyz";
    if(strlen(reference) != ALPHABET_SIZE) printf("Reference size is wrong. Size: %ld\n", strlen(reference));
    short* offset = malloc(sizeof(short) * ALPHABET_SIZE);
    for(int i = 0; i < ALPHABET_SIZE; i++)
    {
        char currentLetter = reference[i];
        int index = searchLetter(rotorCharacters, currentLetter, ALPHABET_SIZE);
        if(index < 0)
        {
            puts("Algo deu errado.");
            exit(1);
        }
        short difference = reference[index] - currentLetter;
        offset[i] = difference >= 0 ? difference: difference + 26;
    }
    return offset;
}

int searchLetter(char* array, char letter, size_t size)
{
    for(unsigned int i = 0; i < size; i++)
    {
        if(tolower(array[i]) == tolower(letter)) return i;
    }
    return -1;
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

/* Teste */