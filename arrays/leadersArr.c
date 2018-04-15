#include <stdio.h>


void findLeader(int *arr, int len)
{

int max = 0;
int i=0;

max = arr[len-1];

printf("\n %d \t", max); //rightmost elem is always a leader
for(i=len-2; i>=0; i--)
{
  if(arr[i] > max)
  {
    max = arr[i];
    printf("%d \t", max);
  }
}

}

int main()
{

int arr[]={4, 20, 12, 7, 5, 9};
int len = sizeof(arr)/sizeof(*arr);


findLeader(arr, len);

return 0;
}
