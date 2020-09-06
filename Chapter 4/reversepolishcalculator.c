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

int getop(char a[]);
int getopstr(char a[] , char b[]); 
void push(double);
double pop(void);
void print(void);
int getloc(void);
int method(int input , char s[] , char block[]);
void swap(void);
void clear(void);
void ungets(char s[]);
int getlin(char s[] , int lim);

int var[VARLEN];

void main()
{

    int type;
    double op2;
    double op1;
    char s[MAXOF];
    char block[MAXOF];
    double actualval;

    int j;
    for( j = 0 ; j<VARLEN ; j++)
    {
	var[j] = 0;
    }

    printf("NOTE: print represented by @\n");
    printf("NOTE: swap represented by #\n");
    printf("NOTE: sin represented by &\n");
    printf("NOTE: exp represented by ~\n");
    printf("NOTE: pow represented by ^\n");
    printf("NOTE: assignment represented by =\n");
    printf("NOTE: clear represented by $\n\n");

    printf("Enter desired method of calculator\n");
    int input;
    scanf("%d\n",&input);

    while((type = method(input,s,block)) != EOF && type != 0 )
    {
	switch (type) 
	{
	    case NUMBER :
		push(atof(block));
		break;
	    case VAR_ASSIGN :
		push(block[0]);
		break;
	    case VAR_USED :
		push(var[block[0] - 'a']);
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
		printf("error: unknown command %s\n" , block);
		break;
	}
    }
}

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

int getloc(void)
{
    return sp-1;
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

int start_block = 0;
int len ;

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

int buf=-99;

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
