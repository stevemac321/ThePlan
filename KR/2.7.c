#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_digit(char c)
{
    if(c >= '0' && c <= '9')
        return true;

    return false;
}
int  my_atoi(char s[])
{
    int neg = 0;

    if(*s == '-') {
        neg = 1;
    }
    int total = 0;
    for(int i = neg; is_digit(s[i]); i++) {
        total = 10 * total + (s[i] - '0');
    
    }

    if(neg == 1)
        total = -total;

    return total;
}
char my_lower(int c)
{
    if(c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
int main()
{
    printf("%d\n", my_atoi("-345"));
    printf("%d\n", my_atoi("345"));

}
