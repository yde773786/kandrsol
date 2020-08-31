#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int strrindex(char s[] , char t[]);

void main()
{

    int i , c;
    char s[MAXLINE];
    char t[MAXLINE];

    printf("Enter main string\n");	
    for(i = 0 ; i< MAXLINE && (c=getchar()) != EOF ; i++)
    {
	s[i] = c;
    }
    s[i] = '\0';
    putchar('\n');

    printf("Enter substring to be checked\n");
    for(i = 0 ; i< MAXLINE && (c=getchar()) != EOF ; i++)
    {
	t[i] = c;
    }
    t[i] = '\0';
    putchar('\n');

    printf("%d\n" , strrindex(s,t));

}

int strrindex(char s[] , char t[])
{
   
    int i,j,k;
    int tLength = strlen(t);
    int sLength = strlen(s);

    if(sLength >= tLength)
    {
	for(i = sLength - tLength ; i>=0 ; i--)
	{
	    for(j = i , k = 0 ; j < i + tLength; j++,k++)
	    {
		if(s[j] != t[k])
		{
		    break;
		}
	    }
	    if(j== i + tLength)
	    {
	    	return i;
	    }
	}
	return -1;
    }
    return -1;

}
