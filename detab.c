#include <stdio.h>
#define TABSPACE 4
#define IN 1
#define OUT 0

void putspace(int x);

main()
{
    int checker = OUT;
    int cnt;
    int c;
    cnt =0;
    while((c=getchar()) != EOF)
    {
         ++cnt;
	 if(c=='\n')
	 {
	     putchar(c);
	     cnt = 0;
	 }
	 else if(c=='\t')
	 {
	     int adder;
	     adder = TABSPACE - ((cnt-1)%TABSPACE);
	     putspace(adder);
	     cnt+=adder-1;

	 }
	 else
	 {
	     putchar(c);
	 }
    }
}

void putspace(int x)
{
    int cnt;
    for(cnt = 0 ; cnt<x; ++cnt)
    {
	printf(" ");
    }
}

