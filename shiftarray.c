#include <stdio.h>
#ifndef _countof
#define _countof(x) sizeof(x) / sizeof(x[0])
#endif

void insert_val_at(int ar[], const int val, const unsigned long pos, const unsigned long arlen)
{
  unsigned long cur = arlen -1;
  while(cur > pos) {
    ar[cur] = ar[cur-1];
    --cur;

  }
  if(cur >= 0)
    ar[cur] = val;
}

int main(int argc, char *argv[])
{
  int a[] = {0,1,2,3,4,5,6,7,8,9,0,0,0,0,0};
  const unsigned long len = _countof(a);
 
  for(int i=0; i < len; i++)
    printf("%d\n", a[i]);

  puts("\n");
  insert_val_at(a, 66, 5, len);

  for(int i=0; i < len; i++)
    printf("%d\n", a[i]);

  puts("\n");
  insert_val_at(a, 66, 0, len);

  for(int i=0; i < len; i++)
    printf("%d\n", a[i]);
}
