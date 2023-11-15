/** @file input.h
 *  @brief Function protypes for input related usage.
 * 
 *  These functions can be used to check get user input, check it,
 *  store it in variables and more.
*/

#pragma once

#define EXIT_KEYBOARD 1
#define EXIT_SETTINGS 1
#define EXIT_MAIN_MENU 1

extern int messageWordCount;
extern char word[300];
extern char lastLetter;

/** @brief Checks the last user input when in the keyboard and calls functions accordingly.
 *  @return Escape ascii number (27) if escape key is pressed, else returns 0.
*/
int checkKeyboardInput(void);

/** @brief Checks the last user input when in the main menu and calls functions accordingly.
 *  @return Escape ascii number (27) if escape key is pressed, else returns 0.
*/
int checkMainMenuInput(void);

/** @brief Checks the last user input when in the settings menu and calls functions accordingly.
 *  @return Escape ascii number (27) if escape key is pressed, else returns 0.
*/
int checkSettingsInput(void);

/** @brief Loops the printKeyboardMenu and the checkKeyboardInput functions.
 *  @return Void.
*/
void goToKeyboard(void);

/** @brief Prints the settings and checks for user input.
 *  @return Void.
*/
void goToSettings(void);

/** @brief Loops the printRotorSettingsScreen and checkSettingsInput functions.
 *  @return Void.
*/
void goToRotorSettings(void);

/** @brief Loops the printPlugboardSettingsScreen and getInput functions.
 *  @return Void.
*/
void goToPlugboardSettings(void);

/** @brief Loops the printKeyboardSettingsScreen and getInput functions.
 *  @return Void.
*/
void goToKeyboardSettings(void);

/** @brief Save the last word and starts quitting the program.
 *  @return Escape ascii number (27).
*/
int saveAndQuitLoop(void);

/** @brief Used to start saving a new world.
 *  @return Void.
*/
void startNewWord(void);

/** @brief Used to start saving a new message.
 *  @return Void.
*/
void startNewMessage(void);

/** @brief Resets the messageWordCount variable.
 *  @return Void.
*/
void resetMessageWordCount(void);

/** @brief Appends the given letter to the "word" string.
 * 
 *  Besides appending this letter to the "word" string, this function will also
 *  store this letter in the "lastLetter" variable.
 * 
 *  @param letter The letter to be saved.
 *  @return Void.
*/
void saveLetter(char letter);

/** @brief Resets the variable "word" and clears the last letter stored.
 *  @return Void.
*/
void resetWord(void);

/** @brief Gets the user input from the stdin.
 * 
 *  This function returns every character that's being sent
 *  by the user, without them needing to press the enter key.
 * 
 *  @return The character inputted by the user.
*/
char getInput(void);