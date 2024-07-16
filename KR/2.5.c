#include <stdio.h>

void leapyear(int year) 
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("%d is a leap year\n", year);
    else
        printf("%d is NOT a leap year\n", year);

}
int main()
{
    for(int i = 1956; i < 2025; i++)
        leapyear(i);

   printf("%d\n", 1900 % 4);
   printf("%d\n", 1900 % 100);
   printf("%d\n", 1900 % 400);
}
