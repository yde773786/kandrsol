#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
    int c,state;
    int cnt_words;
    state = OUT;
    cnt_words = 0;
while((c=getchar())!=EOF){
	if(c==' ' || c=='\n' || c == '\t'){
	    state = OUT;
	}
	else if(state == OUT)
	{
	    putchar('\n');
	    state=IN;
	    ++cnt_words;
	    printf("word %d" , cnt_words);
	    putchar('|');
	}
	else if(state ==IN){
	    putchar('|');
	 }
  }
 }
