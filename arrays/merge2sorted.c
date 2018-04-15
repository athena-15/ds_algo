#include <stdio.h>


void moveToEnd(int *mPlusN, int m, int n)
{
int i = 0;
int j = m + n -1;

for(i = m+n-1; i>=0; i--)
{
  if(mPlusN[i] != -1)
  {
    mPlusN[j] = mPlusN[i];
    j--;
  }
}

}


void merge(int *mPlusN, int *N, int m, int n)
{
int i = n; //end of smaller array
int j = 0;
int k = 0;

while(k < (m+n))
{
  if ((i < (m+n) && mPlusN[i] <= N[j]) || (j == n))
  {
    mPlusN[k] = mPlusN[i];
    k++;
    i++;
  }
  else
  {
    mPlusN[k] = N[j];
    j++;
    k++;
  }
}
}

void printArr(int *arr, int len)
{
int i=0;

for(i=0; i < len; i++)
{
  printf("\n %d\n", arr[i]);
}

}
int main()
{

int mPlusN[] = {2, -1, 7, -1, -1, -1, 10};
int N[] = {5, 8, 12, 14};

int n = sizeof(N)/sizeof(*N);
int m = sizeof(mPlusN)/sizeof(*mPlusN) - n;

moveToEnd(mPlusN, m, n);

merge(mPlusN, N, m, n);

printArr(mPlusN, (m+n));
return 0;
}
