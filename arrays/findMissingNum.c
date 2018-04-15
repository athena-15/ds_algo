#include <stdio.h>

/*
int findMissingNum(int *arr, int len)
{
  int total =((len+1) * (len+2))/2;

  for(int i = 0; i < len; i++)
  {
    total-= arr[i];
  }
return total;
}
*/


int findMissingNum(int *arr, int len)
{
  int xor1 = arr[0];
  int xor2 = 1;
  int ans = 0;

  for(int i=1; i<len; i++)
  {
    xor1 = xor1 ^ arr[i];
  }
  for(int i=2; i<=len+1; i++)
  {
    xor2 = xor2 ^ i;
  }

  ans = xor1 ^ xor2;

  return ans;
}


int main()
{
  int arr[] = {1, 2, 4, 5, 6, 7, 8};
  int len = sizeof(arr)/sizeof(*arr);

  int ans = findMissingNum(arr, len);
  printf("\n %d\n", ans);

return 0;
}
