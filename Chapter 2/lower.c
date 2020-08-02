#include <stdio.h>
#define MAXLINE 1000

void lower(char input[]);

void main()
{

    char input[MAXLINE];
    int i,c;
  
    printf("Enter string\n");
    for(i=0 ; (c=getchar())!=EOF; i++)
    {
	input[i] = c;
    }
    putchar('\n');
    input[i] = '\0';
    lower(input);
    printf("%s\n", input);

}

void lower(char input[])
{
    int i;
    for(i = 0 ; i<MAXLINE && input[i]!='\0';i++)
    {
	input[i] = (input[i]>='A' && input[i]<='Z') ? input[i]='a'+input[i]-'A' : input[i];
    }
}

