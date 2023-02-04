/** @file ui.h
 *  @brief Function prototypes for the user interface.
 * 
 *  This header contains prototypes for clearing and printing
 *  to the terminal.
*/

#pragma once

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"

enum state { DISAPPEAR, REAPPEAR };

/** @brief Prints the menu onto the screen.
 *  @return Void.
*/
void printMenu(void);

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

/** @brief Prints a new line character to the stdout.
 *  @return Void.
*/
void printNewLine(void);

/** @brief Prints a given number of spaces to the stdout.
 *  @param numberOfSpaces Number of spaces to be printed.
 *  @return Void.
*/
void printSpaces(int numberOfSpaces);

/** @brief Clears the screen.
 *  
 *  The same as the shell command "clear".
 * 
 *  @return Void.
*/
void clearScreen(void);

/** @brief Changes the state of the cursor visibility.
 *  @param cursorState What cursor state to change to - either "DISAPPEAR" or "REAPPEAR".
 *  @return Void.
*/
void changeCursorVisibility(enum state cursorState);