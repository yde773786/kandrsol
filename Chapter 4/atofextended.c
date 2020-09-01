#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

double extendedatof(char s[]);

void main()
{
   
    int i,c;
    char s[MAXLINE];
    printf("Enter main string\n");	
    for(i = 0 ; i< MAXLINE && (c=getchar()) != EOF ; i++)
    {
	s[i] = c;
    }
    s[i] = '\0';
    
    printf("\n%g\n" , extendedatof(s));

}

double extendedatof(char s[])
{

    double val,power;
    int i , sign , powersign , e;

    for(i = 0 ; isspace(s[i]) ; i++)
	;
    sign = (s[i] == '-') ? -1 : 1;

    if(s[i] == '+' || s[i] == '-')
    {
	i++;
    }

    for(val = 0.0 ; isdigit(s[i]) ; i++)
    {
	val = 10.0 * val + (s[i] - '0');
    }

    if(s[i] == '.')
    {
	i++;
    
   }

   for(power = 1.0 ; isdigit(s[i]) ; i++)
   {
       val = 10.0 * val + (s[i] - '0');
       power *= 10.0;
   }

    
   if(s[i] == 'E' || s[i] == 'e')
   {
	i++;
   }

   powersign = (s[i] == '-') ? -1 : 1;

   if(s[i] == '+' || s[i] == '-')
   {
	i++;
   }

   for(e = 0 ; isdigit(s[i]) ; i++)
   {
       e = 10*e + (s[i] - '0');
   }

   int cnt;
   for(cnt = 1 ; cnt <= e ; cnt++)
   {
       if(powersign==-1)
       {
	   power *= 10.0;
       }
       else 
       {
	   power /= 10.0;
       }
   }
   
   return sign * val / power;

}

