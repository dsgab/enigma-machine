#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file-operations.h"
#include "ui.h"
#include "strings.h"
#include "input.h"

FILE* encryptionOutputFile;
char encryptionOutputFileName[] = "output.txt";
int messageNumber = 1;

void initializeOutputFile(void)
{
    if(openOutputFile() == EXIT_FAILURE) exit(1);
}

int openOutputFile(void)
{
    encryptionOutputFile = fopen(encryptionOutputFileName, "w");
    if(!encryptionOutputFile)
    {
        printf("Could not open output file.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void closeOutputFile(void)
{
    if(fclose(encryptionOutputFile) == EOF) puts("Output file could not be closed.");
}

void startNewMessage(void)
{
    if(messageWordCount != 0 || isStringEmpty(word)) return;
    if(messageNumber > 1) fputs("\n", encryptionOutputFile);    /* Only writes new line to output file if it's not the first message */
    fprintf(encryptionOutputFile, "Message %i:\n", messageNumber++);
}

void saveWordToFile(void)
{
    if(isStringEmpty(word)) return;
    if(messageWordCount > 0) fputs(" ", encryptionOutputFile);
    fputs(word, encryptionOutputFile);
    messageWordCount++;
}