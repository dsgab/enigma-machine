#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "encryption.h"

void allocateRotor(rotor* rotorName)
{
    rotorName = malloc(sizeof(rotor));
}