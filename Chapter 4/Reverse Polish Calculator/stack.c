#include <stdio.h>
#include "calc.h"

static int sp = 0;
static double val[MAXVAL];

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

