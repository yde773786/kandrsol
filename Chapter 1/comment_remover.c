#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLINE 1000
void main()
{
  
    int c;
    char input[MAXLINE];
    int i,pointer_star,quotes;
    
    for(i = 0 ;(c=getchar())!=EOF;++i)
    {
	input[i] = c;
    }
    input[i] = '\0';

    i = 0;
    pointer_star = OUT;
    quotes = OUT;
    while(input[i]!='\0')
    {
       
       if(input[i]=='/' && input[i+1]=='*'&&quotes==OUT)
       {
	   pointer_star = IN;
       }
       else if(input[i]=='"')
       {
	   if(quotes==OUT)
	   {
	     quotes = IN;
	   }
	   else
	   {
	       quotes = OUT;
	   }
	   putchar(input[i]);
       }
       else if(pointer_star == IN && input[i]=='/' && input[i-1]=='*'&&quotes==OUT)
       {
	   pointer_star = OUT;
       }
       else if(pointer_star==OUT)
       {
	   putchar(input[i]);
       }
       ++i;
    }
}

	   


