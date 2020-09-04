#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAXOF 100
#define NUMBER '0'
#define VAR_USED '('
#define VAR_ASSIGN ')'
#define VARLEN 26

int getop(char []);
void push(double);
double pop(void);
void print(void);
void swap(void);
void clear(void);
void ungets(char s[]);

int var[VARLEN];

void main()
{

    int type;
    double op2;
    double op1;
    char s[MAXOF];
    double actualval;

    int j;
    for( j = 0 ; j<VARLEN ; j++)
    {
	var[j] = 0;
    }

    printf("NOTE: UNARY '-' represented by !\n");
    printf("NOTE: print represented by @\n");
    printf("NOTE: swap represented by #\n");
    printf("NOTE: sin represented by &\n");
    printf("NOTE: exp represented by ~\n");
    printf("NOTE: pow represented by ^\n");
    printf("NOTE: assignment represented by =\n");
    printf("NOTE: clear represented by $\n\n");

    while((type = getop(s)) != EOF)
    {
	switch (type) 
	{
	    case NUMBER :
		push(atof(s));
		break;
	    case VAR_ASSIGN :
		push(s[0]);
		break;
	    case VAR_USED :
		push(var[s[0] - 'a']);
		break;
	    case '+' :
		push(pop() + pop());
		break;
	    case '*' :
		push(pop() * pop());
		break;
	    case '-' :
	        op2 = pop();
                push(pop() - op2);
		break;
	    case '/' :
		op2 = pop();
		if(op2!=0.0)
		{
		    push(pop() / op2);
		}
		else
		{
		    printf("error: zero divisor\n");
		}
		break;
	    case '%' :
		op2 = pop();
		op1 = pop();
		if((op2 == (int) op2) && (op1 == (int) op1))
		{
		   push((int)op1 % (int)op2);
		}
		else
		{
		    printf("error: mod with floating point\n");
		}
		break;
	    case '~' :
		push(exp(pop()));
		break;
	    case '&' :
		push(sin(pop()));
		break;
	    case '^' :
		op2 = pop();
		op1 = pop();
		if((op2 == 0 && op1 <=0) || (op2 <0 && op1 != (int) op1))
		{
		    printf("error: domain issues");
		}
		else
		{
       		    push(pow(op1 , op2));
		}
		break;
	    case '@':
                print();
		break;
            case '#':
		swap();
		break;
	    case '$' :
		clear();
		break;
	    case '=' :
		op1 = pop();
		op2 = pop();
		var[(int)op1 - 'a'] = op2;
		break;
	    case '\n' :
		printf("\t%.8g\n" , pop());
		break;
	    default :
		printf("error: unknown command %s\n" , s);
		break;
	}
    }
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
    {
	val[sp++] = f;
    }
    else
    {
	printf("error: stack full, can't push %g\n" , f);
    }
}

double pop(void)
{
    
    if(sp >0)
    {
	return val[--sp];
    }
    else
    {
	printf("error: stack empty\n");
	return 0.0;
    }
}

void print(void)
{
    if(sp>0)
    {
       printf("%g" , val[sp-1]);
    }
    else
    {
	printf("error: stack empty\n");
    }
}

void swap(void)
{
    if(sp>1)
    {
       double op1 = pop();
       double op2 = pop();
       push(op1);
       push(op2);
    }
    else
    {
	printf("eror: not enough elements to swap in stack\n");
    }
}

void clear(void)
{
    while(sp>0)
    {
	pop();
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{

    int i , c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
	;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '!' && !islower(c))
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
    if(c == '!')
    {
        s[i] = '-';
        while(isdigit(s[++i] = c = getch()))
	    ;
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

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
    {
	printf("ungetch : too many characters\n");
    }
    else
    {
	buf[bufp++] = c;
    }
}

void ungets(char s[])
{
    int i = strlen(s)-1;
    while(i >= 0)
    {
 	ungetch(s[i]);
    }
}


