#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

static int buf=-99;

int getch(void)
{
    if(buf==-99)
    {
	return getchar();
    }
    else
    {
	int tmp = buf;
	buf = -99;
	return tmp;
    }
}

void ungetch(int c)
{
   buf = c;
}

void ungets(char s[])
{
    int i = strlen(s)-1;
    while(i >= 0)
    {
 	ungetch(s[i]);
    }
}

