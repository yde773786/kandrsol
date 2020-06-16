#include <stdio.h>
#define IN 1
#define OUT 0
#define TABSPACE 4

void main()
{
    int c,state,space_cnt,char_cnt;
    state=0;
    space_cnt=0;
    char_cnt=0;
    while((c=getchar())!=EOF)
    {
	++char_cnt;
	if(c==' ')
	{
	    ++space_cnt;
	    --char_cnt;
	    state = IN;
	}
	else if(c!=' ' && state==IN)
	{
	    state = OUT;
	    int tmp;
	    while((tmp = TABSPACE - ((char_cnt-1)%TABSPACE)) <= space_cnt)
	    {
		putchar('-');
		char_cnt += tmp;
		space_cnt-=tmp;
	    }
	    if(space_cnt!=0){
		for(int i = 1 ; i<=space_cnt;i++,++char_cnt)
		{
		    putchar('.');
		}
	    }
	    putchar(c);
	    space_cnt=0;
	}
	else if(c=='\n')
	{
	    space_cnt=0;
	    char_cnt=0;
	    putchar(c);
	}
	else
	{
	    space_cnt=0;
	    putchar(c);
	}
    }
}




