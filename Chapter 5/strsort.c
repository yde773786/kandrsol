#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 5000

char* lineptr[MAXLINES];

int readlines(char* lineptr[], int maxlines, int maxlength, char alloc[]);
void writelines(char* lineptr[], int nlines);

void qsort(char* lineptr[], int left, int right);
void swap(char* v[], int i, int j);

int main()
{
    int nlines;
    char alloc[MAXLEN];

    if ((nlines = readlines(lineptr, MAXLINES, MAXLEN, alloc)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("%s\n", "error: input too big to sort");
        return 1;
    }
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

int readlines(char* lineptr[], int maxlines, int maxlength, char alloc[])
{
    int len, nlines;
    char* p, line[maxlength];
    char* current = alloc;

    nlines = 0;
    while((len = getlin(line, maxlength)) > 0)
    {
        if(current + len > alloc + maxlength)
        {
            current = NULL;
        }

        if(nlines >= maxlines || (p = current) == NULL)
        {
            return -1;
        }
        else
        {
            current += len;
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char* lineptr[], int nlines)
{
    int i;

    for(int i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}

/*From Section 4*/
void qsort(char* v[], int left, int right)
{
  int i, last;

  if(left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;

  for(i = left + 1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);

  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char* v[], int i, int j)
{
    char* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
