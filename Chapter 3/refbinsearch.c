#include <stdio.h>

int refbinsearch(int x , int v[], int n);

void main()
{

    printf("Enter length of array\n");
    int length;
    scanf("%d",&length);
    char c;
    int v[length];
    int i;

    printf("Enter array of integers \n");
    for (i=0; i<length ; i++)
    {
	int tmp;
        scanf("%d",&tmp);
	v[i] = tmp;
	putchar('\n');
    }
    v[i] = '\0';

    printf("Enter value to search for\n");
    int input;
    scanf("%d",&input);

    printf("refbinsearch output: %d\n" , refbinsearch( input , v , length ));

}

int refbinsearch(int x , int v[], int n)
{
    int low , high , mid;

    low = 0;
    high = n - 1;
    while(low<high){
    	mid = (low+high) / 2 ;
	if(x <= v[mid])
	{
	   high = mid;
	}
	else
	{
	  low = mid + 1;
        }
   }

   return x==v[low] ? low : -1;	

}

