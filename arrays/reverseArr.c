#include <stdio.h>


void revArr_rec(int *arr, int start, int end)
{
  int temp;

  if(start >= end)
    return;

  temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;

  revArr_rec(arr, start+1, end-1);

}


void revArr(int *arr, int len)
{
int temp;
int start = 0;
int end = len-1;

while(start<end)
{
temp = arr[start];
arr[start] = arr[end];
arr[end] = temp;

start++;
end--;
}


}


int main()
{
int i;

int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int len = sizeof(arr)/sizeof(*arr);

revArr(arr, len);

for(i = 0; i<len; i++)
{
printf("\n %d \n", arr[i]);
}

revArr_rec(arr, 0, len-1);

for(i = 0; i<len; i++)
{
printf("\n %d \n", arr[i]);
}

return 0;
}
