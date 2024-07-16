#include <stdio.h>
void swap(int a[], int dex1, int dex2)
{
  int tmp = a[dex2];
  a[dex2] = a[dex1];
  a[dex1] = tmp;
}
void rotate_right(int ar[], const unsigned int pos, const int len) 
{
  for(int i=0; i < pos; i++) {
    int right = len -1;

    while(right > 0){
	    swap(ar,right, right - 1);
	    right--;
    }
  }
}

void rotate_left(int ar[], const unsigned int pos, const int len) 
{
  for(int i=0; i < pos; i++) {
    int left = 0;

    while(left < len-1){
	    swap(ar,left, left+1);
	    left++;
    }
  }
}
int main(int argc, char *argv[])
{
  int a[]={1,2,3,4,5};
  rotate_right(a, 2, 5);

  for(int i=0; i < 5; i++)
    printf("%d\n", a[i]);

  puts("-----------------\n");
  int a2[]={1,2,3,4,5};
  rotate_left(a2, 2, 5);

  for(int i=0; i < 5; i++)
    printf("%d\n", a2[i]);
}
