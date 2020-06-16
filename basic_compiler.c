#include <stdio.h>
#define MAXLINE 1000
#define YES 1
#define NO 0

int pushChar(char a);
int popChar(char a);
void push(char stack[] , char a);
void pop(char stack[]);
int matcher(char a , char b);
int top; 
void main()
{
    int last_slash , within_quotes_d , within_quotes_s, within_comments,last_star;
    int c;
    top = 0;   
    last_slash = NO;
    last_star = NO;
    within_quotes_d = NO;
    within_quotes_s= NO;
    within_comments= NO;
    char stack[MAXLINE];
    stack[0] = '\0';

    while((c=getchar())!=EOF)
    {
	
	if(within_comments == YES && c=='/' && last_star == YES)
	{
	    push(stack,'*');
	    pop(stack);
	    within_comments = NO;
	}
        
	if(within_quotes_d == YES && c=='"')
	{
	    within_quotes_d = NO;
	}
	
	if(within_quotes_s == YES && c=='\'')
	{
	    within_quotes_s = NO;
	}

	if(last_slash==YES && c == '\\')
	{
	    last_slash=NO;
	}
        
	if((pushChar(c)==YES||popChar(c)==YES) && last_slash==NO && within_quotes_s==NO && within_quotes_d==NO && within_comments==NO)
	{  
	    push(stack,c);
            printf("[PUSH] %s  TOP:%d \n" , stack,top);
	}
	if(popChar(c)==YES && last_slash==NO && within_quotes_s==NO && within_quotes_d==NO && within_comments==NO)
	{
	    pop(stack);
	}
        
	if(c=='\\')
	{
	    last_slash=YES;
	}
	else
	{
	    last_slash=NO;
	}
	
	if(c=='*')
	{
	    last_star=YES;
	}
	else
	{
	    last_star=NO;
	}
	
	if(stack[top-1]=='"')
	{
	    within_quotes_d = YES;
	}

	if(stack[top-1]=='\'')
	{
	    within_quotes_s = YES;
	}

	if(stack[top-1]=='*')
	{
	    within_comments = YES;
	}

    }
    
    if(stack[0]=='\0')
    {
	printf("UNBALANCED CHECKER FINDS NO ERRORS");
    }
    else
    {
	printf("UNBALANCED. CURRENT STACK: %s" , stack);
    }

}

int pushChar(char a)
{
    if(a=='{' || a=='(' || a=='[' ||  a=='"' || a == '\''|| a == '/'||a=='*')
    {
	return YES;
    }
    return NO;
}


int popChar(char a)
{
    if(a=='}' || a==')' || a==']' ||  a=='"' || a == '\'' || a == '/'|| a== '*')
    {
	return YES;
    }
    return NO;
}

int matcher(char a , char b)
{

    if(a=='{' && b=='}')
    {
	return YES;
    }
    else if(a=='[' && b==']')
    {
	return YES;
    }
    else if(a=='"' && b=='"')
    {
	return YES;
    }
    else if(a=='\'' && b=='\'')
    {
	return YES;
    }
    else if(a=='(' && b==')')
    {
	return YES;
    }
    else if(a=='*' && b=='*')
    {
	return YES;
    }
    else if(a=='/' && b=='/')
    {
	return YES;
    }
    else
    {
	return NO;
    }

}

void push(char stack[] , char add)
{
    stack[top] = add;
    ++top;
    stack[top] = '\0' ;
}

void pop(char stack[])
{
    if(top>=2)
    {
      if(matcher(stack[top-2] , stack[top-1])==YES)
      {
	  top-=2;
	  stack[top] = '\0';
          printf("[POP] %s  TOP:%d \n" , stack,top);
      }
    }
}
