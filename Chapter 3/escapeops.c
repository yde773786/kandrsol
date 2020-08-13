#include <stdio.h>
#define MAXLINE 100

void escape(char s[] , char t[]);
void revescape(char s[] , char t[]);

void main()
{

    int c,i;
    char inputstr[MAXLINE];
    char outputstr[MAXLINE];

    printf("Enter string\n");
    for(i = 0 ; i<MAXLINE && (c=getchar())!=EOF ; i++)
    {
	inputstr[i] = c;
    }
    inputstr[i] = '\0';

    printf("Enter 1 for escape and 0 for revescape\n");
    int choice;
    scanf("%d",&choice);
    
    if(choice)
    {
	escape(inputstr,outputstr);
    }
    else
    {
 	revescape(inputstr,outputstr);
    }
    printf("%s", outputstr);

}

void escape(char s[] , char t[])
{
    int i,adder;
    adder = 0;
    for(i = 0 ; i<MAXLINE && s[i]!='\0' ; i++)
    {
	switch(s[i]) {
	    case '\n' :
		t[i+adder] = '\\';
		adder++;
		t[i+adder] = 'n';
		break;
	    case '\t' :	
		t[i+adder] = '\\';
		adder++;
		t[i+adder] = 't';
		break;
	    default :
		t[i+adder] = s[i];
	}
    }
}

void revescape(char s[] , char t[])
{
    int i,subber;
    subber = 0;
    for(i = 0 ; i<MAXLINE && s[i]!='\0' ; i++)
    {
	switch(s[i]) {
	    case '\\' : 
		if(s[i+1]=='n')
		{
		    t[i-subber]='\n';
		    subber++;
		    i+=1;
		}
		else if(s[i+1] == 't')
		{
		    t[i-subber] = '\t';
		    subber++;
		    i+=1;
		}
		else
		{
		    t[i-subber] = s[i];
		}
		break;
	    default :
		t[i-subber] = s[i];
	}
    }
}
