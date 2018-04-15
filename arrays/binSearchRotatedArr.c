#include <stdio.h>


int binSearch(int *arr, int low, int high, int key)
{
  if(low > high)
   return -1;

  int mid = low + (high - low)/2;

  if(arr[mid] == key)
    return mid;

  if(arr[low]<arr[mid]) //first half is sorted
  {
    if(arr[low] >= key && key <= arr[mid])
    {
      return binSearch(arr, low, mid - 1, key);
    }
    else
       return binSearch(arr, mid+1, high, key);
  }
  else //second half is sorted
  {
    if(arr[mid] <= key && key <= arr[high])
    {
      return binSearch(arr, mid+1, high, key);
    }
  }
  return binSearch(arr, low, mid - 1, key);
}
int main()
{
  int arr[] = {4, 5, 6, 7, 8, 1, 2, 3};
  int len = sizeof(arr)/sizeof(*arr);
  int key = 7;

  int val = binSearch(arr, 0, len - 1, key);
  printf("\n Idx of %d :: %d \n", arr[val], val);

return 0;
}
