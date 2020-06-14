#include <stdio.h>
main()
{
    int c,i;
    int cnt['}'-'!'];
  
    for(i='!'; i<'}' ; i++)
    {
	cnt[i-'!']=0;
    }
    
    while((c=getchar())!=EOF)
    {
	++cnt[c-'!'];
    }
    for(i='!' ; i<'}' ; i++)
    { 
	if(cnt[i-'!']!=0){
	    putchar(i);
	}
	int j;
	for(j = 0; j<cnt[i-'!'] ; j++)
	{
	    printf("|");
	}
	if(cnt[i-'!']!=0)
	{
	   putchar('\n');	    
	}
    }
        
}
