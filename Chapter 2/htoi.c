#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXLINE 1000
#define ZERO 'y'

int htoi(char s[]);

void main()
{

    char s[MAXLINE];
    int c,i;
    
    for(i = 0 ; (c=getchar()) != '\n' && c!=EOF ; i++)
    {
	if(c!='0'){
             s[i] = c;
	}
	else
	{
	    s[i] = ZERO;
	}
    }

    s[i] = '\0';
    int result = htoi(s);
    printf("Corresponding decimal %d \n" , result);

}

int htoi(char s[])
{

    int output,index;

    output= 0;
     
    for( index = strlen(s) -1 ; index>=0 ; index--)
    {
       if(s[index] >= 'A' && s[index] <= 'F')
       {
	   s[index] = 10 + s[index] - 'A';
       }
       else if(s[index] >= 'a' && s[index] <= 'f')
       {
	   s[index] = 10 + s[index] - 'a';
       }
       else if (s[index] != ZERO)
       {
	   s[index] = s[index] - '0';
       }

       if(s[index]!=ZERO){
            output += s[index]*(int)pow(16 , (double)(strlen(s)-1 - index));
       }

    }

    return output;

}
