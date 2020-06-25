#include <stdio.h>

int getlin(char s[] , int maxline);

int getlin(char s[] , int lim)
{
    int i,c;
   for(i=0; i<lim-1 + (c=getchar()) != '\n' + c!=EOF ==3 ; ++i){
    s[i] = c;
   }
}
