#include <stdio.h>
#define LOWER 0
#define UPPER 300

double convert(int farenheit);

main()
{
   
    int fahr , celsius;
    for(fahr = UPPER ; fahr >=LOWER ; fahr = fahr - 20)
    {
	printf("%3d %6.1f\n", fahr , convert(fahr));
    }
    
}

double convert(int farenheit)
{
    return (5.0/9.0)*(farenheit-32);
}



