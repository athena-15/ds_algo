#include <stdio.h>


int findMaxFreqElem(int *arr, int len)
{
  int cnt = 0;
  int max = -1;
  int curr = arr[0];
  int maxVal = curr;

  for(int i = 0; i<len; i++)
  {
   if(arr[i] == curr)
   {
    cnt++;
   }
   else
   {
     if(cnt > max)
     {
       max = cnt;
       maxVal = curr;
     }
     cnt = 0; //reset the cnt
     curr = arr[i];
     
   }
  }
  if(cnt > max)
  {
    maxVal = curr;
  }
  return maxVal;
}
int main()
{
  int arr[] = {1, 2, 2, 3, 4, 5, 5, 5, 6, 7, 7};
  int len = sizeof(arr)/sizeof(*arr);
  int ans = findMaxFreqElem(arr, len);

  printf("\n Max freq elem is :: %d \n", ans);

return 0;
}
