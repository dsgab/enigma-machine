#include "general-use-ui.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printNewLine(void) { putchar('\n'); }

void printSpaces(int numberOfSpaces) {
  for (int i = 0; i < numberOfSpaces; i++)
    putchar(' ');
}

void clearScreen(void) { system("clear"); }

void changeCursorVisibility(enum cursorState state) {
  switch (state) {
  case DISAPPEAR:
    printf("\033[?25l");
    break;
  case REAPPEAR:
    printf("\033[?25h");
    break;
  }
}
