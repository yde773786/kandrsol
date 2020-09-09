#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void itoa(int n, char s[]);
void reverse(char s[]);

void main()
{

    char s[MAXLINE];

    printf("Enter 1 for itoa and 2 for reverse\n");
    int choice;
    scanf("%d",&choice);


    if(choice==1)
    {
        printf("Enter numeric input\n");
        int n;
        scanf("\n%d",&n);
	itoa(n,s);
    }
    else
    {
	int i,c;
	for(i = 0 ; i<MAXLINE && (c=getchar()) != EOF ; i++)
	{
	    s[i] = c;
	}
	s[i] = '\0';
	reverse(s);
    }

    printf("\n%s\n", s); 

}

int i = 0;
void itoa(int n, char s[])
{
    if (n < 0)
    {
	s[i++] = '-';
	n = -n;
    }
    if(n / 10)
    {
	itoa(n/10, s);
    }
    s[i++] = n % 10 + '0';
}

int j = 0;
void reverse(char s[])
{
    if(j >= strlen(s)/2)
    {
	return;
    }
    else
    {
	char tmp = s[j];
        s[j] = s[strlen(s)-j-1];
	s[strlen(s)-j-1] = tmp;
	j++;
	return reverse(s);
    }
}
