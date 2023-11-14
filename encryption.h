/** @file encryption.h
 *  @brief Function protypes for encryption related usage.
 * 
 *  Something.
*/

#pragma once

#define ALPHABET_SIZE 26

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

/** @brief Encrypts the last letter received from the standard input.
 *  @param letter The letter to be encrypted.
 *  @return The resulting encrypted letter.
*/
char encryptLetter(char letter);

/** @brief Allocate and intialize the three rotors.
 *  @return Void.
*/
void initializeRotors(void);

/** @brief Allocates and initializes a single rotor.
 *  @param rotor The address of the rotor pointer.
 *  @param rotorOffsetIn The array of offsets of the rotor for a letter going for the first time through it.
 *  @param rotorOffsetOut The array of offsets of the rotor for a letter going for the second time through it.
 *  @param nextRotor The rotor to be rotated when this rotor hits its notch.
 *  @param notchPosition The position of the notch.
 *  @return Void.
*/
void initializeRotor(ROTOR** rotor, short* rotorOffsetIn, short* rotorOffsetOut, ROTOR* nextRotor, short notchPosition);

/** @brief Rotates a given rotor.
 *  @param rotor The rotor to be rotated.
 *  @return Void.
*/
void rotateRotor(ROTOR* rotor);

/** @brief Makes the current encrypted letter go through three rotors in a given order.
 *  @param first The first rotor that the letter should go through.
 *  @param second The second rotor that the letter should go through.
 *  @param third The third rotor that the letter should go through.
 *  @return Void.
*/
void goThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third);

/** @brief Makes the current encrypted letter go through three rotors in a given order.
 * 
 *  Used only when the encrypted letter has already passed through the reflector.
 * 
 *  @param first The first rotor that the letter should go back through.
 *  @param second The second rotor that the letter should go back through.
 *  @param third The third rotor that the letter shoudl go back through.
 *  @return Void.
*/
void returnThroughRotors(ROTOR* first, ROTOR* second, ROTOR* third);

/** @brief Makes the current encrypted letter pass through a rotor, changing it to another letter.
 *  @param rotor Rotor that the letter should pass through.
 *  @return Void.
*/
void goThroughRotor(ROTOR* rotor);

/** @brief Makes the current encrypted letter pass thorugh a rotor, changing it to another letter.
 * 
 *  Used only when the encrypted letter has already passed through the reflector.
 * 
 *  @param rotor Rotor that the letter should go through.
 *  @return Void.
*/
void returnThroughRotor(ROTOR* rotor);

/** @brief Calculates the position of the letter based on the rotor position and the letter value.
 *  @param rotorCurrentPosition The current position of the rotor.
 *  @param encryptedLetter The current encrypted letter.
 *  @return The position of the letter.
*/
short calculateLetterPosition(short rotorCurrentPosition, char encryptedLetter);

/** @brief Changes the current encrypted letter based on a given offset.
 *  @param offset The number to be added to the original letter to get the new letter.
 *  @return Void.
*/
void changeEncryptedLetter(short offset);

/** @brief Changes the letter based on the reflector array.
 *  @param letterToBeReflected The letter to be reflected.
 *  @return Void.
*/
void reflectLetter(char letterToBeReflected);

/** @brief Allocates space in memory for the rotor.
 *  @return A pointer to the rotor that's being allocated.
*/
ROTOR* allocateRotor(void);

/** @brief Frees the space in memory that's being allocated to all the three rotors.
 *  @return Void.
*/
void freeRotors(void);

/** @brief Gets the current position of a given rotor.
 * 
 *  Used on the UI to get the rotor position and print it on the screen.
 * 
 *  @param rotor The rotor from where to get the current position from.
 *  @return The current position of the rotor from 1 to 26.
*/
short getRotorCurrentPosition(ROTOR* rotor);