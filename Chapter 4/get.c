#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);
int getfloat(float *pn);

void main()
{

    printf("Enter choice 1 for getint and 2 for getfloat\n");
    int choice;
    getint(&choice);
    putchar('\n');

    if(choice == 1)
    {
	printf("Enter some integer input\n");
	int int_input;
	getint(&int_input);
	putchar('\n');
	printf("%d" , int_input);
	printf("\n");
    }
    else
    {
	printf("Enter some float input\n");
	float float_input;
	getfloat(&float_input);
	putchar('\n');
	printf("%g" , float_input);
	printf("\n");
    }

}

int getint(int *pn)
{
    int c, sign;
    
    while(isspace(c=getch()))
	;
    if(!isdigit(c) && c!=EOF && c!= '+' && c != '-')
    {
	ungetch(c);
	return 0;
    }
    sign = (c=='-') ? -1 : 1;
    if(c== '+' || c == '-')
    {
        while(isspace(c=getch()))
             ;
    }
    for(*pn = 0 ; isdigit(c); c = getch())
    {
	*pn = 10 * *pn + (c-'0');
    }
    *pn *= sign;
    if(c != EOF)
    {
	ungetch(c);
    }
    return c;
}

int getfloat(float *pn)
{

    int c, sign, cnt;
    cnt = 1;
    while(isspace(c=getch()))
	;
    if(!isdigit(c) && c!=EOF && c!= '+' && c != '-' && c != '.')
    {
	ungetch(c);
	return 0;
    }
    sign = (c=='-') ? -1 : 1;
    if(c== '+' || c == '-')
    {
        while(isspace(c=getch()))
             ;
    }
    for(*pn = 0 ; isdigit(c); c = getch())
    {
	*pn = 10 * *pn + (c-'0');
    }
    if(c== '.')
    {
        while(isspace(c=getch()))
             ;
    }
    for(; isdigit(c); c = getch())
    {
	*pn = 10 * *pn + (c - '0');
        cnt*=10;
    }
    *pn = (*pn * sign) / cnt;
    if(c != EOF)
    {
	ungetch(c);
    }
    return c;
}

static int buf = -99;

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

