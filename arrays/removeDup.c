#include <stdio.h>


int removeDups(int *arr, int len)
{

int *curr = arr;
int *result = arr;
int newLen = 0;
int i = 0;

for(i=0; i<len; i++)
{
  if(i==0)
  {
    newLen++;
  }
  else
  {
    if(*curr != *result) //unique chars
    {
      *(++result) = *curr;
      newLen++;
    }
  }
  curr++;
  
}

return newLen;

}


int main()
{

int arr[] = {1, 2, 3, 3, 4, 5, 5, 6};
int len = sizeof(arr)/sizeof(*arr);
int i = 0;

int newLen = removeDups(arr, len);

for(i=0; i<newLen; i++)
{
  printf("\n %d \t", arr[i]);
}
return 0;
}
