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

void rotateRotor(ROTOR* rotor);