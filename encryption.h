/** @file encryption.h
 *  @brief Function protypes for encryption related usage.
 * 
 *  Something.
*/

#pragma once

typedef struct _rotor
{
    char lettersToAdvance[26];
    int notchPosition;
}
rotor;

rotor rotorOne;