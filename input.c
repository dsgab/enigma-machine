#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "input.h"
#include "ui.h"
#include "strings.h"
#include "file-operations.h"

#define ESCAPE_KEY 27
#define ESPACE_KEY 32
#define RETURN_KEY 13
#define BACKSPACE_KEY 127

int messageWordCount = 0;   /* Number of words in the current message being typed */
char word[300];     /* Word that's being currently typed */
char lastLetter;    /* Last letter inputted by the user */

int checkInput(void)
{
    char character = getInput();
    if(isCharacterLetter(character)) saveLetter(character);
    if(character == ESPACE_KEY) startNewWord();
    if(character == RETURN_KEY) startNewMessage();
    if(character == ESCAPE_KEY) return saveAndQuitLoop();
    return 0;
}

int saveAndQuitLoop(void)
{
    startWritingNewMessage();
    saveWordToFile();
    return 1;
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
    system("/bin/stty raw");
    answer = getc(stdin);
    system("/bin/stty cooked");
    return answer;
}