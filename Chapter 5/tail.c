#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLINE 100
#define DEFAULT 10
#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;

void tail(char** output, int limiter);

int main(int argc, char* argv[]) {
    int limiter;

    if(argc >= 3 && strcmp(argv[1], "-n"))
    {
        limiter = atoi(argv[2]);
    }
    else
    {
        limiter = DEFAULT;
    }

    char* output[MAXLINE];
    tail(output, limiter);

    int i;
    for(i = 0; i < limiter; i++)
    {
        printf("%s\n", *output);
    }
    return 0;
}

int getlin(char* s, int lim);

/* From strptr.c */
int getlin(char* s, int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n' ; i++, s++)
    {
        *s = c;
    }
    if(c=='\n')
    {
        *s=c;
        ++i;
    }
    *s='\0';
    return i;
}

char* alloc(int n);

void tail(char** output, int limiter)
{
    char* input[MAXLINE];
    char line[MAXLINE];
    char* p;
    char* q;

    int i = 0;
    while(getlin(line, MAXLINE) && (p = alloc(strlen(line))) != NULL)
    {
        strcpy(p, line);
        input[i++] = p;
    }

    int j = 0;
    int tail_start = i < limiter ? 0 : (i-1) - (limiter-1);

    while(j < i && j < limiter && (q = alloc(strlen(line))) != NULL)
    {
       strcpy(q, input[tail_start + j]);
       output[j++] = q;
    }
}

/** From Adress Arithmetic subsection **/
char *alloc(int n) /* return pointer to n characters */
 {
     if (allocbuf + ALLOCSIZE - allocp >= n)
     { /* it fits */
         allocp += n;
         return allocp - n; /* old p */
     }
     else /* not enough room */
     {
         return 0;
     }
 }
