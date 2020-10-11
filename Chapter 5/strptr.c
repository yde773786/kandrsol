#include <stdio.h>
#define MAXLINE 100 

void strconcat(char* s, char* t);
int strend(char* s , char* t);
void strncopy(char* s, char* t, int n);
void strnconcat(char* s, char* t, int n);
int strncompare(char* s, char* t, int n);
char* commonton(char* t, int n);
int getlin(char* s, int lim);
int atoi(char* s);
void itoa(int val, char* s);
void reverse(char* s);
int strindex(char* s, char* t);

int main()
{

    char s[MAXLINE];
    char t[MAXLINE];
    int choice;
    int i,c,n;

    printf("Enter choice of operation\n");
    scanf("%d", &choice);
    c = getchar();

    if(choice != 6 && choice != 8)
    {
   	 printf("Enter string s \n");
   	 for(i = 0 ; i<MAXLINE && (c=getchar()) != EOF && c!='\n' ; i++)
   	 {
		s[i] = c;
   	 }
   	 s[i] = '\0';
    }
    if(choice == 1 || choice == 2 || choice == 4 || choice == 5 || choice == 10)
    {
	printf("ENTER string t \n");
    	for(i = 0 ; i<MAXLINE && (c=getchar()) != EOF &&c!='\n' ; i++)
   	{
	   t[i] = c;
        }
	t[i] = '\0';
    }
    if(choice == 3 || choice == 4 || choice == 5 || choice == 8)
    {
	printf("Enter n\n");
	scanf("%d", &n);
    }

    if(choice==1)
    {
	strconcat(s,t);
	printf("%s\n",s);
    }
    else if(choice==2)
    {
	printf("%d\n",strend(s,t));
    }
    else if(choice==3)
    {
	strncopy(t, s, n);
	printf("%s\n", t); 
    }
    else if(choice==4)
    {
	strnconcat(s,t,n);
	printf("%s\n", s);
    }
    else if(choice==5)
    {
	printf("%d\n", strncompare(s,t,n));
    }
    else if(choice==6)
    {
	char each_line[MAXLINE];
	printf("%s\n", "Enter input");
	while(getlin(each_line, MAXLINE)>0)
	{
	    printf("%s\n", each_line);
	}
    }
    else if(choice==7)
    {
	printf("%d\n", atoi(s));
    }
    else if (choice==8)
    {
	itoa(n, s);
	printf("%s\n",s);
    }
    else if(choice==9)
    {
	reverse(s);
	printf("%s\n",s);
    }
    else if(choice==10)
    {
	printf("%d\n", strindex(s, t));
    }
}

void strconcat(char* s, char* t)
{
    while(*s++)
	;
    s--;
    while(*s++ = *t++)
    	;
}

int strend(char* s , char* t)
{
    char* t_end = t;
    while(*t_end++)
	;
    t_end--;
    int t_len = t_end - t;
    char* s_end = s;
    while(*s_end++)
	;
    s_end--;
    int s_len = s_end - s;
    if(s_len >= t_len)
    {
	char* s_start = s_end - t_len;
	while(*s_start++ == *t++ && *(t-1))
	    ;
	s_start--;
	if(s_start == s_end)
	{
	    return 1;
	}
    }
    return 0;
}

char* commonton(char* t, int n)
{
    char* t_end = t;
    while(*t_end++)
	;
    t_end--;
    int t_len = t_end - t;
    int i = 0;
    char* n_end = t+n;

    if(t_len < n)
    {
	while(++t_end < n_end)
	{
	    *t_end = '\0';
	}
    }
    return n_end;
}


void strncopy(char* s, char* t, int n)
{
    char* n_end = commonton(t, n);
    while(t < n_end)
    {
	*s++ = *t++;
    }
    *s = '\0';
}


void strnconcat(char* s, char* t, int n)
{
    char* n_end = commonton(t, n);
    
    while(*s++)
	;
    s--;
    while(t < n_end)
    {
	*s++ = *t++;
    }
    *s = '\0';	
}

int strncompare(char* s, char* t, int n)
{
    char* n_end = commonton(t, n);

    for( ; *s == *t ; s++, t++)
    {
	if(*s == '\0')
	{
	    return 0;
	}
	else if(t == n_end-1)
	{
	    return *++s;
	}
    }
    return *s - *t;

}

int getlin(char* s, int lim)
{
    int c, i;
    
    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n' ; i++, s++)
    {
	*s = c;
    }
    if(c=='\n')
    {
        *s=c;
        ++i;
    }
    *s='\0';
    return i;
}

int atoi(char* s)
{
    int output = 0;
    int temp = 0;
    while(temp = *s++)
    {
	output = output * 10 + temp - '0';
    }
    return output;
}

void itoa(int n, char* s)
{
    char* start = s;
    while(n!=0)
    {
	*s++ = '0' + n % 10;
	n /= 10;
    }
    *s = '\0';
    reverse(start);
}

void reverse(char* s)
{
    char* end = s;	
    while(*end++)
	;
    end -= 2;
    for(;end >= s;end--, s++)
    {
	char temp = *end;
	*end = *s;
	*s = temp;
    }
}


int strindex(char* s, char* t)
{
    int t_index = -1;
    int s_index = -1;
    while(*s)
    {
	s_index++;
	char* current = s;
	char* temp = t;
	int completed = 1;
	while(*temp)
	{
	    if(!*current)
	    {
		printf("%c", *current);
		return t_index;
	    }
	    else if(*current != *temp)
	    {
		completed = 0;
		break;
	    }
	    current++;
	    temp++;	
	}
	if(completed)
	{
	    t_index = s_index;
	}
	s++;
    }
    return t_index;
}

