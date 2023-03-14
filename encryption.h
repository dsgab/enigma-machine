/** @file encryption.h
 *  @brief Function protypes for encryption related usage.
 * 
 *  Something.
*/

#pragma once

typedef struct _ROTOR
{
    short* inLettersToAdvance;
    short* outLettersToAdvance;
    short currentPosition;
    short notchPosition;
    struct _ROTOR* nextRotor;
}
ROTOR;

extern ROTOR* firstRotor;
extern ROTOR* secondRotor;
extern ROTOR* thirdRotor;

char encryptLetter(char letter);

void initializeRotors(void);

void initializeRotor(ROTOR** rotor, short* rotorOffsetIn, short* rotorOffsetOut, ROTOR* nextRotor, short notchPosition);

void rotateRotor(ROTOR* rotor);

void goThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third);

void returnThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third);

void goThroughRotor(ROTOR* rotor);

void returnThroughRotor(ROTOR* rotor);

short calculateLetterPosition(short rotorCurrentPosition, char inputLetter);

void changeEncryptedLetter(short offset);

char reflectLetter(char letterToBeReflected);

ROTOR* allocateRotor(void);

void freeRotors(void);

/** @brief Gets the current position of a given rotor.
 * 
 *  Used on the UI to get the rotor position and print it on the screen.
 * 
 *  @param rotor The rotor from where to get the current position from.
 *  @return The current position of the rotor from 1 to 26.
*/
short getRotorCurrentPosition(ROTOR* rotor);