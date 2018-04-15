#include <stdio.h>

void reverse(int *arr, int *left, int *right)
{
  int temp;

  while(left<right)
  {
    temp=*left;
    *left=*right;
    *right=temp;

    left++;
    right--;
  }
}

void rotate(int *arr, int len, int k)
{
  reverse(arr, &arr[0], &arr[len-1]); //reverse whole array
  reverse(arr, &arr[0], &arr[k-1]);
  reverse(arr, &arr[k], &arr[len-1]);
}
int main()
{
  int i = 0;
  int arr[]={1, 2, 3, 4, 5};
  int size = sizeof(arr)/sizeof(*arr);
  int k = 3;

  for(i=0;i<size; i++)
  {
    printf("\n %d", arr[i]);
  }
  printf("\n");
  rotate(arr, size,k);
  for(i=0;i<size;i++)
  {
    printf("\n %d", arr[i]);
  }

  return 0;

}
