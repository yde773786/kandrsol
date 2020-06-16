 #include <stdio.h>
#define n 14
#define MAXLINE 1000
#define YES 1
#define NO 0

int checkLimitCross(int i , char input[],int pointer);

void main()
{
    int c;
    char input[MAXLINE];
    int i,pointer;
    int last_space;
    for(i = 0 ;(c=getchar())!=EOF;++i)
    {
	input[i] = c;
    }
    input[i] = '\0';
    last_space = 0;
    putchar(input[0]);
    pointer =1;
    for(i=1 ; input[i]!='\0' ; ++i,++pointer)
    {
	if((input[i]==' ')&&(input[i-1]!=' '))
	{
	    if(checkLimitCross(i,input,pointer)==YES)
	    {
		putchar('\n');
		pointer = 0;
	    }
	    else
	    {
		putchar(input[i]);
	    }
	}
	else if((input[i]!=' ')&&(input[i-1]==' '))
	{
	    putchar(input[i]);
	    last_space = i;
	}
	else
	{
	    putchar(input[i]);
	}
	if(input[i]=='\n')
	{
	    pointer = 0;
	    last_space=0;
	}
	if((pointer+1)==n)
	{
	    putchar('\n');
	    pointer = 0;
	}
    }
   
}

int checkLimitCross(int i , char input[], int pointer)
{
    int j;
    int k;
    
    for(j = i+1, k = pointer+1; (input[j]!='\0')&&(input[j]!='\n')&&!((input[j]==' ')&&(input[j-1]!=' '));++j,++pointer)
    {

	if((pointer+1)==n)
	{
	    return 1;
	}
    }
    return 0;
}


