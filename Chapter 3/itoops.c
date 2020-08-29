#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void twosComplementItoa(int n, char s[]);
void itob(int n , char s[] , int b);
void limitItoa(int n , char s[] , int limiter);
void reverse(char s[]);

void main()
{
    printf("Enter input  value to be converted\n");
    int input;
    scanf("%d",&input);

    printf("Enter choice of program to execute\n");
    int choice;
    scanf("%d",&choice);

    char output[MAXLINE];

    if(choice==1)
    {
	twosComplementItoa(input , output);
    }
    else if(choice==2)
    {
        printf("Enter base value\n");
        int base;
        scanf("%d",&base);
	itob(input , output , base);
    }
    else
    {
        printf("Enter limiter\n");
        int limiter;
        scanf("%d",&limiter);
	limitItoa(input , output , limiter);
    }
    printf("OUTPUT :%s\n" , output);

}

void twosComplementItoa(int n , char s[])
{
    int i , sign;

    if(n < 0)
    {
	sign = -1;
    }
    else
    {
	sign = 1;
    }
    n = n*sign;

    i = 0;
    do
    {
	s[i++] = n % 10 + '0';
    } while((n/=10) > 0);
    if(sign == -1)
    {
	s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);

}

void itob(int n , char s[] , int base)
{
    int i , sign;

    if(n<0)
    {
	sign = -1;
    }
    else
    {
	sign = 1;
    }
    n = n*sign;

    i = 0;
    do
    {
 	s[i++] = (base==16 && n%base>9) ? n%base-10 + 'A' : n%base + '0';
    } while((n/=base) > 0);

    if(sign <0)
    {
	s[i++] = '-';
    }
    s[i] = '\0';

   reverse(s);
}
 
void limitItoa(int n , char s[] , int limiter)
{
    twosComplementItoa(n,s);
    reverse(s);
    if(strlen(s) < limiter)
    {
	int i;
	for(i = strlen(s) ; i<limiter ; i++)
	{
	    s[i] = '_';
	}
	s[i] = '\0';
    }
    reverse(s);
}

void reverse(char s[]){

    int c , i , j;

    for(i = 0 , j = strlen(s)-1 ; i<j ; i++ , j--)
    {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
    }
}
