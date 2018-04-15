#include <stdio.h>
#include <stdlib.h>

int getOddOccur(int *arr, int len)
{
  int i;
  int res = 0;

  for(i = 0; i<len; i++)
  {
    res ^= arr[i];
  }
  return res;
}

int main()
{
  int arr[] = {1, 2, 3, 1, 2, 3, 4, 3, 4};
  int len = sizeof(arr)/sizeof(*arr);

  printf("\n %d \n", getOddOccur(arr, len));
  return 0;
}
