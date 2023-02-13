#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"

ROTOR* allocateRotor()
{
    return malloc(sizeof(ROTOR));
}