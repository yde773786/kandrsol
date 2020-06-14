#include <stdio.h>
#define MAXLINE 1000
#define YES 1
#define NO 0

int getlin(char line[] , int maxline);
void reverse(char input[],int lim);

main()
{
   
   char line[MAXLINE];
   while(getlin(line,MAXLINE)==0)
   {
       reverse(line,MAXLINE);
       printf("%s" , line);
   }
   return 0;
}

int getlin(char s[], int lim)
{
    int c , i,last_non_whitespace;
    last_non_whitespace = -1;
    for(i = 0 ; i <lim -1 && (c= getchar())!=EOF && c!='\n'; ++i)
    {
	s[i] = c;
	if(c!=' ' && c!='\t'){
	    last_non_whitespace=i;
	}
    }
    if(last_non_whitespace!=0){
        i = last_non_whitespace+1;
    }
    if(c == '\n'&&last_non_whitespace!=-1)
      {
	 s[i] = c;
	  ++i;
      }
    s[i] = '\0';
    if(c==EOF)
    {
	return 1;
    }
    else
    {
      return 0;
    }
}


void reverse(char input[] , int lim)
{
    int j , nl_check;
    nl_check = NO;
    for(j=0; j<lim-1 && input[j]!='\0'; ++j)
    {
	if(input[j] == '\n')
	{
	    nl_check = YES ;
	    break;
	}
    }
    
    int i,z;
    char tmp='\0';
    --j;
    for(i=0,z=j; i!=((j+1)/2) ; ++i,--z)
    {
	tmp = input[i];
        input[i] = input[z];
        input[z] = tmp;
    }
    if(nl_check==YES)
    {
	input[++j]='\n';
    }
    input[++j] = '\0';
}
