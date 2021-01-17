#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define DEFTAB 4

void entab(int start, int tabspace, char* output);
void assignval(char* argv[], int* loc);

int main(int argc, char *argv[]) {
    int start;
    int tabspace = DEFTAB;
    char output[MAXLINE];

    if(argc == 3)
    {
        ++argv;
        assignval(argv, &start);
        ++argv;
        assignval(argv, &tabspace);
    }
    entab(start, tabspace, output);
    printf("\n%s\n", output);
    return 0;
}

void entab(int start, int tabspace, char* output)
{
    int c;
    int temp = 0;
    int tabcnt = 0;
    char buffer[tabspace];
    buffer[0] = '\0';

    while((c = getchar()) != EOF)
    {
        if(c == ' ' && tabcnt % tabspace != 0)
        {
            buffer[temp] = c;
            *(buffer + temp + 1) = '\0';

            temp++;
            tabcnt++;
        }
        else if(c != '\n')
        {
            temp = 0;
            if(tabcnt % tabspace == 0 && strlen(buffer) != 0)
            {
                buffer[0] = '\t';
                buffer[1] = '\0';
            }

            int i;
            for(i = 0; i < tabspace && buffer[i]; i++)
            {
                *output++ = buffer[i];
            }
            buffer[0] = '\0';

            if(c == ' ')
            {
                buffer[0] = ' ';
                buffer[1] = '\0';
            }
            else
            {
                *output++ = c;
            }

            tabcnt++;
        }
        else
        {
            temp = 0;
            *output++ = c;
        }

    }
    *output = '\0';
}

void assignval(char* argv[], int* loc)
{
    ++*argv;
    *loc = atoi(*argv);
}
