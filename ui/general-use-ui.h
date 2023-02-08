/** @file general-use-ui.h
 *  @brief Useful UI related functions that may be used several times.
*/

#pragma once

enum state { DISAPPEAR, REAPPEAR };

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
 *  @param cursorState What cursor state to change to; either "DISAPPEAR" or "REAPPEAR".
 *  @return Void.
*/
void changeCursorVisibility(enum state cursorState);