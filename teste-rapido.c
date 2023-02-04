#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int allocateString(void);

int main() {
    char pa1[100] = "teste ";
    char *p1;
    char *p2 = "a";

    p1 = (char*) malloc(20);
    for(int i = 0; i < 6; i++)
    {
        *(p1+i) = pa1[i];
    }
    puts(p1);
    puts(p2);
    strcat(p1, p2);
    puts(p1);
    puts(p2);

   return 0;
}

int allocateString(void)
{

}