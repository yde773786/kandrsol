#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

void main()
{
    printf("%s\n", "Enter choice");
    char choice = getchar() - '0';
    getchar();
    int year, month, day;

    if(choice)
    {
        printf("%s\n", "Enter year");
        scanf("%d", &year);

        printf("%s\n", "Enter month");
        scanf("%d", &month);

        printf("%s\n", "Enter day");
        scanf("%d", &day);

        printf("Day of year: %d\n", day_of_year(year, month, day));
    }
    else
    {
        printf("%s\n", "Enter year");
        scanf("%d", &year);

        int yearday;
        printf("%s\n", "Enter day of year");
        scanf("%d", &yearday);

        month_day(year, yearday, &month, &day);
        printf("Month: %d\nDay: %d\n", month, day);
    }
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if(year >= 0 && 1 <= month && month <= 12 && 1 <= day &&
    day <= daytab[leap][month]){
        for(i = 1; i < month; i++)
        {
            day += daytab[leap][i];
        }
        return day;
    }
    else
    {
        printf("%s\n", "Invalid input");
        return -1;
    }
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if(year >= 0 && 1 <= yearday && yearday <= 365 + leap)
    {
        for(i = 1; yearday > daytab[leap][i]; i++)
        {
            yearday -= daytab[leap][i];
        }
        *pmonth = i;
        *pday = yearday;
    }
    else
    {
        printf("%s\n", "Invalid input");
        *pmonth = -1;
        *pday = -1;
    }

}
