/** @file encryption.h
 *  @brief Function protypes for encryption related usage.
 * 
 *  Something.
*/

#pragma once

typedef struct _ROTOR
{
    short *lettersToAdvance;
    short currentPosition;
    short notchPosition;
    struct _ROTOR* nextRotor;
}
ROTOR;

char encryptLetter(char letter);

void initializeRotors(void);

void initializeRotor(ROTOR** rotor, short* rotorOffset, ROTOR* nextRotor, short notchPosition);

void rotateRotor(ROTOR* rotor);

void goThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third);

void goThroughRotor(ROTOR* rotor);

void changeEncryptedLetter(short offset);

ROTOR* allocateRotor(void);