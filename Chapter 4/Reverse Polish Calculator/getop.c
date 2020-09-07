#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int method(int input , char s[] , char block[])
{
    if(input == 1)
    {
	return  getop(block);
    }
    else
    {
	return getopstr(s,block);
    }
}

int getop(char s[])
{

    int i , c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
	;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-' && !islower(c))
    {
	return c;
    }
    i = 0;
    if(islower(c))
    {
	while((c = getch()) == ' ' || c== '\t')
	    ;
       ungetch(c);
	if(c=='=')
	{
	    return VAR_ASSIGN;
	}
	return VAR_USED;
    }
    if(c == '-')
    {
	if(getloc() <= 0)
	{
           s[i] = '-';
           while(isdigit(s[++i] = c = getch()))
	       ;
	}
	else
        {
	    return c;
	}
    }
    if(isdigit(c))
    {
	while(isdigit(s[++i] = c = getch()))
	    ;
    }
    if(c == '.')
    {
	while(isdigit(s[++i] = c = getch()))
	    ;
    }
    s[i] = '\0';

    ungetch(c);
    return NUMBER;

}

static int start_block = 0;
static int len ;

int getopstr(char expression[] , char block[])
{

    if(start_block == 0)
    {
       len = getlin(expression,MAXVAL);
    }

    int i;
    for(i=start_block ; i < len ; i++)
    {

	int j,c;
	while((block[0] = c = expression[i++]) == ' ' || c == '\t')
	    ;
	block[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-' && !islower(c))
        {
	   start_block = (c == '\n') ? 0 : i ;
           return block[0];
        }
	j = 0;
	if(islower(c))
	{
	    while((c = expression[i++]) == ' ' || c == '\t')
		;
            start_block = i-1;
	    if(c == '=')
	    {
		return VAR_ASSIGN;
	    }
	    return VAR_USED;
	}
	if(c == '-')
        {
	    if(getloc() <= 0)
	    {
		block[0] = '-';
		while(isdigit(block[++j] = c = expression[i++]))
		    ;
	    }
	    else
	    {
		start_block = i;
		return c;
	    }
	}
	if(isdigit(c))
	{
	    while(isdigit(block[++j] = c = expression[i++]))
		;
	}
	if(c == '.')
	{
	    while(isdigit(block[++j] = c = expression[i++]))
		;
	}

	block[j] = '\0';
	start_block = i - 1;
	return NUMBER;

    }
}

/*From Chapter 1*/
int getlin(char s[],int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n' ; i++)
    {
        s[i]=c;
    }
    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';
    return i;
}

