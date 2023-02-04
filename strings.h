/** @file strings.h
 *  @brief Function prototypes that manipulate strings.
 * 
 *  These functions can be used to modify, check and do other
 *  tasks related to strings.
*/

#pragma once

/** @brief Checks if a given string has only the '\0' character.
 *  @param string The string to check.
 *  @return True if the string is empty or false if the string is not empty.
*/
bool isStringEmpty(char* string);

/** @brief Checks if the given character is a letter.
 *  @param letter The character to check.
 *  @return True if the character is a letter or false otherwise.
*/
bool isCharacterLetter(char letter);

/** @brief Gives an index number based on the position of the given letter in the alphabet.
 *  @param letter The letter to check the index.
 *  @return The number of the index of the given letter.
*/
unsigned char indexInAlphabet(char letter);

/** @brief Concatenate a character to the end of a string.
 *  @param string The string where the character will be appended.
 *  @param character The character to be appended to the end of the string.
 *  @return Void.
*/
void concatenateCharacter(char* string, char character);

/** @brief Deletes the last character of a string.
 *  @param string String to have the last character deleted.
 *  @return Void.
*/
void deleteStringLastCharacter(char* string);