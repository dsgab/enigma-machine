/** @file file-operations.h
 *  @brief Function prototypes for file related operations.
 * 
 *  These functions can be used to open, close and write to an output
 *  file and other related operations.
*/

#pragma once

/** @brief Opens output file and checks for errors.
 *  @return Void.
*/
void openOutputFile(void);

/** @brief Closes output file and checks for errors.
 *  @return Void.
*/
void closeOutputFile(void);

/** @brief Starts wrigin a new message to the output file.
 *  @return Void.
*/
void startWritingNewMessage(void);

/** @brief Saves the last word to the output file.
 *  @return Void.
*/
void saveWordToFile(void);