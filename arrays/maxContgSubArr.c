#include <stdio.h>


int maxContigSubArr(int *arr, int len)
{

int max_so_far = 0;
int max_ending_here = 0;

for(int i=0; i<len; i++)
{
  max_ending_here = arr[i] + max_ending_here;
  if(max_ending_here < 0)
    max_ending_here = 0;

  if(max_so_far < max_ending_here)
    max_so_far = max_ending_here;
}

return max_so_far;
}

int main()
{

int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
int len = sizeof(arr)/sizeof(*arr);

int ans = maxContigSubArr(arr, len);

printf("\n %d\n", ans);

return 0;
}
