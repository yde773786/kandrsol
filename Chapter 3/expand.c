#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

void expand(char s1[] , char s2[]);
void printchain(char target[] , char startChar , char endChar , int startIndex);
void main()
{

    char s1[MAXLINE];
    char s2[MAXLINE];
    int i,c;
    printf("Enter string\n");
    for(i = 0 ; i<MAXLINE && (c=getchar())!=EOF ; i++)
    {
	s1[i] = c;
    }
    s1[i] = '\0';

    expand(s1,s2);
    printf("\n%s" , s2);

}

void expand(char s1[] , char s2[])
{

    int i,cnt;
    for(i = 0 , cnt = 0 ; s1[i]!='\0' ; i++, cnt++)
    {
	int end_chk;
	end_chk = s1[i+1] =='\0' || s1[i+2] == '\0' ? 0 : 1;
	if(islower(s1[i]) && s1[i+1]=='-' && islower(s1[i+2]) && end_chk)
	{
	    printchain(s2 , s1[i] , s1[i+2] , cnt);
	    cnt += (s1[i+2] - s1[i]) -1;
            i += 1;
	}
	else if(isupper(s1[i]) && s1[i+1]=='-' && isupper(s1[i+2]) && end_chk)
	{
	    printchain(s2 , s1[i] , s1[i+2] , cnt);
	    cnt += (s1[i+2] - s1[i]) -1;
            i += 1;
	}
	else if(isdigit(s1[i]) && s1[i+1]=='-' && isdigit(s1[i+2]) && end_chk)
	{
	    printchain(s2 , s1[i] , s1[i+2] , cnt);
	    cnt += (s1[i+2] - s1[i]) -1;
            i += 1;
	}
        else
	{
	    s2[cnt]=s1[i];
	}
	
    }

    s2[cnt] = '\0';

}

       	
void printchain(char target[] , char startChar , char endChar , int startIndex)
{

    int i;
    for(i = startIndex ; i< startIndex + endChar-startChar ; i++)
    {
	target[i] = startChar + i - startIndex;
    }

}
  
