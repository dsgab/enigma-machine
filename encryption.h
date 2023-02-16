/** @file encryption.h
 *  @brief Function protypes for encryption related usage.
 * 
 *  Something.
*/

#pragma once

typedef struct _ROTOR
{
    short lettersToAdvance[26];
    short currentPosition;
    short notchPosition;
    struct _ROTOR* nextRotor;
}
ROTOR;

ROTOR* allocateRotor(void);

char encryptLetter(char letter);

void initializeRotors(void);

ROTOR* initializeRotor(short* rotorOffset, ROTOR* nextRotor, short notchPosition);

void rotateRotor(ROTOR* rotor);

void goThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third);

void goThroughRotor(ROTOR* rotor);

void changeEncryptedLetter(short offset);