#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int method(int input , char s[] , char block[])
{
    if(input == 1)
    {
	return  getop(block);
    }
    else if(input == 2)
    {
	return noungetchgetop(block);
    }
    else if(input == 3)
    {
	return getopstr(s, block);
    }
    else
    {
	return getoptr(block_ptr);
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

static int prev = -99;

int noungetchgetop(char s[])
{

    int i , c;

    while((s[0] = c = next()) == ' ' || c == '\t')
	;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-' && !islower(c))
    {
	return c;
    }
    i = 0;
    if(islower(c))
    {
	while((c = next()) == ' ' || c== '\t')
	    ;
        prev = c;
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
           while(isdigit(s[++i] = c = next()))
	       ;
	}
	else
        {
	    return c;
	}
    }
    if(isdigit(c))
    {
	while(isdigit(s[++i] = c = next()))
	    ;
    }
    if(c == '.')
    {
	while(isdigit(s[++i] = c = next()))
	    ;
    }
    s[i] = '\0';

    prev = c;
    return NUMBER;

}

/* getopptr is from Chapter 5. Please ignore if on Chapter 4 and come back if on Chapter 5 Ex 6*/
int getoptr(char* s)
{

    int i , c;

    while((*s = c = getch()) == ' ' || c == '\t')
	;
    *(s+1) = '\0';
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
           *(s+i) = '-';
           while(isdigit(*(s + ++i) = c = getch()))
	       ;
	}
	else
        {
	    return c;
	}
    }
    if(isdigit(c))
    {
	while(isdigit(*(s + ++i) = c = getch()))
	    ;
    }
    if(c == '.')
    {
	while(isdigit(*(s + ++i) = c = getch()))
	    ;
    }
    *(s+i) = '\0';

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

int next(void)
{
    if(prev == -99)
    {
       return getch();
    }
   else
    {
	int tmp = prev;
	prev = -99;
	return tmp;
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


