#include <stdio.h>
#include <stddef.h>


#define _countof(x) sizeof(x) / sizeof(x[0])
void printa(int a[], const int size)
{
    for(int i=0; i < size; i++) 
        printf("%d ", a[i]);
        
    puts("\n");
}

int rem(int a[], const int size)
{
    if(size < 2)
        return size;
     
    int left = 0;
    for(int right=1; right<size; right++) 
        if(a[right] != a[left]) 
            a[++left] = a[right];
    
    return left + 1;
}

int main()
{
    int a1[]={1,2,2,3,3,4,5,6};
    int len = rem(a1, _countof(a1));
    printa(a1, len);
    int a2[] = {2,2,2,2};
    len = rem(a2, _countof(a2));
    printa(a2, len);
    
}
