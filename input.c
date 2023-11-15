#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "input.h"
#include "./ui/keyboard-ui.h"
#include "strings.h"
#include "file-operations.h"
#include "./ui/general-use-ui.h"
#include "encryption.h"
#include "./ui/settings-ui.h"

#define ESCAPE_KEY 27
#define ESPACE_KEY 32
#define RETURN_KEY 13
#define BACKSPACE_KEY 127

int messageWordCount = 0;   /* Number of words in the current message being typed */
char word[300];     /* Word that's being currently typed */
char lastLetter;    /* Last letter inputted by the user */

int checkKeyboardInput(void)
{
    char character = getInput();
    if(isCharacterLetter(character)) saveLetter(encryptLetter(character));
    if(character == ESPACE_KEY) startNewWord();
    if(character == RETURN_KEY) startNewMessage();
    if(character == ESCAPE_KEY) return saveAndQuitLoop();
    return 0;
}

int checkMainMenuInput(void)
{
    switch(getInput())
    {
        case '1':
            goToKeyboard();
            break;
        case '2':
            goToSettings();
            break;
        case '3':
            return EXIT_MAIN_MENU;
    }
    return 0;
}

int checkSettingsInput(void)
{
    switch(getInput())
    {
        case '1':
            goToRotorSettings();
            break;
        case '2':
            goToPlugboardSettings();
            break;
        case '3':
            goToKeyboardSettings();
            break;
        case ESCAPE_KEY:
            return EXIT_SETTINGS;
    }
    return 0;
}

void goToKeyboard(void)
{
    while(true)
    {
        printKeyboardMenu();
        if(checkKeyboardInput() == EXIT_KEYBOARD) break;
    }
}

void goToSettings(void)
{
    while(true) /* Change loop later to do while instead of while */
    {
        printSettingsScreen();
        if(checkSettingsInput() == EXIT_SETTINGS) break;
    }
}

void goToRotorSettings(void)
{
    while(true)
    {
        printRotorSettingsScreen();
        if(getInput() == ESCAPE_KEY) break;
    }
}

void goToPlugboardSettings(void)
{
    do
    {
        printPlugboardSettingsScreen();
    }
    while(getInput() != ESCAPE_KEY);
    
}

void goToKeyboardSettings(void)
{
    do
    {
        printKeyboardSettingsScreen();
    }
    while(getInput() != ESCAPE_KEY);
}

int saveAndQuitLoop(void)
{
    startWritingNewMessage();
    saveWordToFile();
    return EXIT_KEYBOARD;
}

void startNewWord(void)
{
    startWritingNewMessage();
    saveWordToFile();
    resetWord();
}

void startNewMessage(void)
{
    startWritingNewMessage();
    saveWordToFile();
    resetMessageWordCount();
    resetWord();
}

void resetMessageWordCount(void)
{
    messageWordCount = 0;
}

void saveLetter(char letter)
{
    lastLetter = letter;
    concatenateCharacter(word, letter);
}

void resetWord(void)
{
    lastLetter = 0;
    word[0] = '\0';
}

char getInput(void)
{
    char answer = 'a';
    system("/bin/stty raw -echo");
    answer = getc(stdin);
    system("/bin/stty cooked echo");
    return answer;
}