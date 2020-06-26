#include <stdio.h>
#define MAXLINE 1000
#define YES 1
#define NO 0

void squeeze(char s1[] , char s2[]);
int any(char s1[] , char s2[]);

void main()
{

    char s1[MAXLINE];
    char s2[MAXLINE];
    int c,i;

    printf("ENTER s1\n");
    for( i = 0 ; (c=getchar())!=EOF && c!='\n' ; i++)
    {
	s1[i] = c;
    }
    s1[i] = '\0';

    c=0;
    printf("ENTER s2\n");
    for( i = 0 ; (c=getchar())!=EOF && c!='\n' ; i++)
    {
	s2[i] = c;
    }
    s2[i] = '\0';

    printf("OUTPUT OF any(s1,s2):  %d \n" , any(s1,s2) );
    squeeze(s1,s2);
    printf("OUTPUT OF sueeze(s1,s2) : s1:  %s " , s1); 

}

void squeeze(char s1[] , char s2[])
{
    int i,j,k,repeat;
    for(i = k = 0 ; s1[i] != '\0' ;  i++)
    {
        repeat = NO;
	for(j = 0 ; s2[j] != '\0' && repeat == NO ; j++)
	{
	    if(s1[i] == s2[j]){
		repeat = YES;
	    }
	}
	if(!repeat)
	{
	    s1[k++] = s1[i];
	}
    }
    s1[k] = '\0';
}
       
int any(char s1[] , char s2[])
{
    int pos,i,j;
    for(i=0 ; s1[i] != '\0'; i++)
    {
	for(j=0 ; s2[j] != '\0' ; j++)
	{
	    if(s1[i]==s2[j])
	    {
		return i;
	    }
	}
    }
    return -1;
}
   
  
