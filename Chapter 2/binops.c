#include <stdio.h>

unsigned int getbits(unsigned int x , int p , int n);
unsigned int setbits(unsigned int x , int p , int n , unsigned int y);
unsigned int invert(unsigned int x , int p , int n);
unsigned int rightrot(unsigned int x , int n);


void main()
{

    int choice;
    printf("Enter choice \n");
    scanf("%d", &choice);

    unsigned int x;
    printf("Enter x \n");
    scanf("%d", &x);

    if(choice == 1)
    {
	int p , n;
	unsigned int y;
	printf("Enter p \n");
        scanf("%d", &p);
	printf("Enter n \n");
        scanf("%d", &n);
	printf("Enter y \n");
        scanf("%d", &y);
	printf("Output: %u " , setbits(x,p,n,y)); 
    }
    if(choice == 2)
    {
	int p , n;
	printf("Enter p \n");
        scanf("%d", &p);
	printf("Enter n \n");
        scanf("%d", &n);
	printf("Output: %d " , invert(x,p,n)); 
    }
    if(choice == 3)
    {
	int  n;
	printf("Enter n \n");
        scanf("%d", &n);
	printf("Output: %u " , rightrot(x,n)); 
    }
    
}

unsigned int setbits(unsigned int x , int p , int n , unsigned int y)
{
    y = y & ~(~0 << n);
    y = y << (p+1-n);
    int trail;
    trail = x & ~(~0 << (p+1-n));
    x = x & (~0 << (p+1));	
    x = (x | y) | trail;
    return x;
}

unsigned int invert(unsigned int x , int p , int n)
{
    unsigned int trail , head;
    trail = x & ~(~0 << (p+1-n)) ;
    head = x & (~0 << (p+1));
    x = ~x;
    x = x & (~0 << (p+1-n));
    x = x & ~(~0 << (p+1));
    x = head | x | trail;
    return x;
}
    
unsigned int rightrot(unsigned int x , int n)
{
    int i ;
    for(i=0 ; i<n ; i++)
    {
	unsigned int lsb, header;
	lsb = x&1;
	header = 0;
	if(lsb==1)
	{
	    header = ~(~0U >> 1);
	}
	x = x>>1;
	x = x|header;
    }
    return x;
}


