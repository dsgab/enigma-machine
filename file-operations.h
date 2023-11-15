/** @file file-operations.h
 *  @brief Function prototypes for file related operations.
 * 
 *  These functions can be used to open, close and write to an output
 *  file and other related operations.
*/

#pragma once

extern FILE* debugFile;
extern char debugFileName[];

/** @brief Opens output file and checks for errors.
 *  @return Void.
*/
void openOutputFile(void);

/** @brief Closes output file and checks for errors.
 *  @return Void.
*/
void closeOutputFile(void);

/** @brief Checks if there is a settings file and creates it if none are found.
 *  @return Void.
*/
void checkSettingsFile(void);

/** @brief Creates a standard settings file based on the original Enigma rotors.
 *  @return Void.
*/
void createDefaultSettingsFile(void);

/** @brief Gets the information stored in the settings file of all three rotors.
 *  @return A string vector with the lines of the settings of each one of the three rotors.
*/
char** getCurrentRotorsInfo(void);

/** @brief Gets the information in the settings of the specified rotor.
 *  @return A string with the line from the settings with the info of the rotor.
*/
char* getCurrentRotorInfo(int rotorNumber);

/** @brief Starts wrigin a new message to the output file.
 *  @return Void.
*/
void startWritingNewMessage(void);

/** @brief Saves the last word to the output file.
 *  @return Void.
*/
void saveWordToFile(void);