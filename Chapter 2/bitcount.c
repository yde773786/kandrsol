# include <stdio.h>

int bitcount(unsigned x);

void main()
{

    unsigned x;
    printf("Enter x \n");
    scanf("%u", &x);
    printf("%u\n" , bitcount(x));
}

int bitcount(unsigned x)
{
    int b;
    
    for(b=0 ; x!=0 ; x&=(x-1))
    {
	b++;
    }
    return b;
}
