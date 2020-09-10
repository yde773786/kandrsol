#include <stdio.h>
#define swap(t,x,y) t temp = x; \
	            x = y; \
		    y = temp;\

void main()
{

        printf("Enter numeric input\n");
        int x;
        scanf("\n%d",&x);
        printf("Enter numeric input\n");
        int y;
        scanf("\n%d",&y);

	swap(int,x,y);
	printf("x: %d y: %d\n", x,y);

}



