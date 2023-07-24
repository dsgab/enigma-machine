/** @file general-use-ui.h
 *  @brief Useful UI related functions that may be used several times.
*/

#pragma once

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define BLACK "\033[30m"

enum cursorState { DISAPPEAR, REAPPEAR };

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
 *  @param state What cursor state to change to; either "DISAPPEAR" or "REAPPEAR".
 *  @return Void.
*/
void changeCursorVisibility(enum cursorState state);