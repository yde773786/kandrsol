#include <limits.h>
#include <stdio.h>

void main()
{
   printf("signed char min : %d\n", SCHAR_MIN);
   printf("signed char max : %d\n", SCHAR_MAX);

   /* there does not appear to be a UCHAR_MIN although its value should be ideally 0*/
   printf("unsigned char max : %d\n", UCHAR_MAX);

   printf("short min : %d\n", SHRT_MIN);
   printf("short max : %d\n", SHRT_MAX);

   printf("int min : %d\n", INT_MIN);
   printf("int max : %d\n", INT_MAX);

   printf("long min : %ld\n", LONG_MIN);
   printf("long max : %ld\n", LONG_MAX);
}
