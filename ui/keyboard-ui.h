/** @file keyboard-ui.h
 *  @brief Function prototypes for the keyboard user interface.
 * 
 *  This header contains prototypes for clearing and printing
 *  the keyboard to the terminal.
*/

#pragma once

/** @brief Prints the keybaord menu to the stdout.
 *  @return Void.
*/
void printKeyboardMenu(void);

void printRotors(void);

/** @brief Prints each one of the three rows of the keyboard.
 *  @return Void.
*/
void printKeyboard(void);

/** @brief Prints a given keyboard row onto the screen.
 * 
 *  Depending on the parameter, it will print the first, second
 *  or third item in the keyboardLayoutRows string array, offseting
 *  the start depending on the desired offset according to the
 *  keyboardLayoutRowOffsets array.
 * 
 *  @param rowNumber Number of the keyboard row to be printed.
 *  @return Void.
*/
void printKeyboardRow(int rowNumber);

/** @brief Prints the letters and the space between them of a given row.
 *  @param rowNumber Number of the keyboard row to be printed.
 *  @return Void.
*/
void printKeyboardRowLetters(int rowNumber);

/** @brief Prints a given letter.
 * 
 *  Based on the ASCII value provided by the function caller, this function
 *  will print the letter to the stdout. The letter will be red if it was
 *  the last letter received from the stdin, otherwise it will be white.
 *  
 *  @param asciiValue ASCII table value for the letter to be printed.
*/
void printKeyboardRowLetter(int asciiValue);