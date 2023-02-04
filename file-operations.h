/** @file file-operations.h
 *  @brief Function prototypes for file related operations.
 * 
 *  These functions can be used to open, close and write to an output
 *  file and other related operations.
*/

#pragma once

void initializeOutputFile(void);
int openOutputFile(void);
void closeOutputFile(void);

void startNewMessage(void);
void saveWordToFile(void);