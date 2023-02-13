/** @file encryption.h
 *  @brief Function protypes for encryption related usage.
 * 
 *  Something.
*/

#pragma once

typedef struct _ROTOR
{
    short lettersToAdvance[26];
    int notchPosition;
    struct _ROTOR* nextRotor;
}
ROTOR;

ROTOR* allocateRotor();