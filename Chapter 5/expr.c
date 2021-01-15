#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 100

void perform(char* operator);
int values[MAXSTACK];
int lastindex = -1;

void main(int argc, char *argv[])
{
    while (--argc >= 1) {
        ++argv;
        if(isdigit(*argv[0]))
        {
            values[++lastindex] = atoi(*argv);
        }
        else
        {
            perform(*argv);
        }
    }
    printf("%d\n", values[0]);
}

void perform(char* operator)
{
    switch (operator[0]) {
        case '+':
            values[lastindex-1] = values[lastindex] +
                                  values[lastindex-1];
                                  break;
        case '*':
            values[lastindex-1] = values[lastindex] *
                              values[lastindex-1];
                                  break;
        case '-':
            values[lastindex-1] = values[lastindex-1] -
                              values[lastindex];
                                  break;
        case '/':
            values[lastindex-1] = values[lastindex-1] /
                               values[lastindex];
                                   break;
        default:
             printf("%s\n", "INVALID INPUT");
    }
    lastindex--;
}
