#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#define MAXOF 100
#define VARLEN 26

static int var[VARLEN];

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

