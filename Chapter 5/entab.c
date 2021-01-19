#include <stdio.h>
#include <stdlib.h>

#define DEFTAB 4
#define MAXARGS 100
#define MAXLINE 500

void entab(int* constTab, int constLen, char* output);
int tabstop(int currentPos, int* constTab, int constLen);
int inDefaultRange(int currentPos, int* constTab, int constLen);

int main(int argc, char* argv[]) {

    int argint[MAXARGS];
    if(argc >= 2)
    {
        int i = 0;
        while(*++argv)
        {
            argint[i++] = atoi(*argv);
        }
    }

    char output[MAXLINE];
    entab(argint, argc-1, output);
    printf("\n%s\n", output);
    return 0;
}

void entab(int* constTab, int constLen, char* output)
{
    int c,i;
    int currentPos = 0;
    int outputCount = 0;
    int spaceCount = 0;

    for(i = 0; (c=getchar()) != EOF && i < MAXLINE; i++)
    {
        if(c == '\n')
        {
            currentPos = 0;
            spaceCount = 0;
            *(output + outputCount++) = c;
        }
        else if(!tabstop(currentPos, constTab, constLen))
        {
            if(c == ' ')
            {
                spaceCount++;
            }
            else
            {
                while(spaceCount > 0)
                {
                    *(output + outputCount++) = ' ';
                    spaceCount--;
                }
                *(output + outputCount++) = c;
            }
            currentPos++;
        }
        else
        {
            if(spaceCount != 0)
            {
                *(output + outputCount++) = '\t';
            }
            spaceCount = 0;

            if(c == ' ')
            {
                spaceCount++;
            }
            else
            {
                *(output + outputCount++) = c;
            }
            currentPos++;
        }
    }
    *(output + outputCount) = '\0';
}

int tabstop(int currentPos, int* constTab, int constLen)
{
    int i;

    for(i = 0; i < constLen; i++)
    {
        if(currentPos == *(constTab + i))
        {
            return 1;
        }
    }

    if(currentPos % DEFTAB == 0 && inDefaultRange(currentPos, constTab,
        constLen))
    {
        return 1;
    }
    return 0;
}

int inDefaultRange(int currentPos, int* constTab, int constLen)
{
    if(constLen == 0)
    {
        return 1;
    }
    else
    {
        int max = *constTab;
        int i;

        for(i = 1; i < constLen; i++)
        {
            if(*(constTab + i) > max)
            {
                max = *(constTab + i);
            }
        }

        if(currentPos > max)
        {
            return 1;
        }
        return 0;
    }
}
