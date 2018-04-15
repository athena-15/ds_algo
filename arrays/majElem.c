#include <stdio.h>
#include <stdlib.h>


int findMajElem(int *arr, int len)
{
  int majIdx = 0;
  int cnt= 1;
  int i = 1;

  for(i = 1; i<len; i++)
  {
    if(arr[majIdx] == arr[i])
      cnt++;
    else
    {
      cnt--;
    }
    if(cnt == 0)
    {
      majIdx = i;
      cnt = 1;
    }
   
  }
  return majIdx;
}

int isMajElem(int *arr, int len, int cand)
{
  int i = 0;
  int cnt = 0;

  for(i = 0; i<len; i++)
  {
   if(arr[i] == arr[cand])
     cnt++;
  }
  if(cnt >= len/2)
    return arr[cand];
  else
    return -1;
}

int main()
{
  int arr[] = {2, 2, 3, 4, 5, 6, 2, 2};
  int len = sizeof(arr)/sizeof(*arr);
  int cand;
  int ans;

  cand = findMajElem(arr, len);
  ans = isMajElem(arr, len, cand);
  
  printf("\n Is Maj Elem: %d \n", ans);

  return 0;
}
