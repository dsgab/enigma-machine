#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file-operations.h"
#include "./ui/keyboard-ui.h"
#include "strings.h"
#include "input.h"
#include "encryption.h"

FILE* debugFile;
char debugFileName[] = "debug.txt";
FILE* encryptionOutputFile;
char encryptionOutputFileName[] = "output.txt";
FILE* settingsFile;
char settingsFileName[] = ".settings.txt";
int messageNumber = 1;

void openOutputFile(void)
{
    encryptionOutputFile = fopen(encryptionOutputFileName, "w");
    if(!encryptionOutputFile)
    {
        printf("Could not open output file.");
        exit(1);
    }
}

void closeOutputFile(void)
{
    fputs("\n", encryptionOutputFile);
    if(fclose(encryptionOutputFile) == EOF) puts("Output file could not be closed.");
}

void checkSettingsFile(void)
{
    settingsFile = fopen(settingsFileName, "r");
    if(!settingsFile) createDefaultSettingsFile();
    if(fclose(settingsFile) == EOF) puts("Settings file could not be closed.");
}

void createDefaultSettingsFile(void)
{
    settingsFile = fopen(settingsFileName, "w");
    fputs("ROTORS:\n", settingsFile);
    fputs("1 17 I EKMFLGDQVZNTOWYHXUSPAIBRCJ\n", settingsFile);
    fputs("2 05 II AJDKSIRUXBLHWTMCQGZNPYFVOE\n", settingsFile);
    fputs("3 22 III BDFHJLCPRTXVZNYEIWGAKMUSQO\n", settingsFile);
    fputs("0 10 IV ESOVPZJAYQUIRHXLNFTGKDCMWB\n", settingsFile);
    fputs("0 26 V VZBRGITYUPSDNHLXAWMJQOFECK\n", settingsFile);
    fputs("0 13 VI JPGVOUMFYQBENHZRDKASXLICTW\n", settingsFile);
    fputs("0 13 VII NZJHGRCXMYSWBOUFAIVLPEKQDT\n", settingsFile);
    fputs("0 13 VIII FKQHTLXOCBJSPDZRAMEWNIUYGV\n", settingsFile);
}

char** getCurrentRotorsInfo(void)
{
    char **rotorsInfo = malloc(3 * sizeof(char*));
    settingsFile = fopen(settingsFileName, "r");
    for(int i = 0; i < 3; i++)
    {
        rotorsInfo[i] = getCurrentRotorInfo(i+1);
    }
    if(fclose(settingsFile) == EOF) puts("Settings file could not be closed.");
    return rotorsInfo;
}

char* getCurrentRotorInfo(int rotorNumber)
{
    char *line = (char*) malloc(100 * sizeof(char));
    bool found = false;
    rewind(settingsFile);
    while(!found)
    {
        fgets(line, 100, settingsFile);
        if(line[0] == rotorNumber + '0') found = true;
        if(feof(settingsFile)) return NULL;
    }
    return line;
}

void startWritingNewMessage(void)
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