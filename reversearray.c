#include <stdio.h>
#ifndef _countof
#define _countof(x) sizeof(x) / sizeof(x[0])
#endif

void reverse_array(int ar[],  const unsigned long arlen)
{
  unsigned long end = arlen -1;
  unsigned long start = 0;
  while(end > start) {
    int tmp = ar[end];
    ar[end] = ar[start];
    ar[start] = tmp;
    start++;
    end--;
  }
}

int main(int argc, char *argv[])
{
  int a[] = {0,1,2,3,4,5,6,7,8,9,0,0,0,0,0};
  const unsigned long len = _countof(a);
 
  for(int i=0; i < len; i++)
    printf("%d\n", a[i]);

  puts("\n");
  reverse_array(a, len);

  for(int i=0; i < len; i++)
    printf("%d\n", a[i]);

}
