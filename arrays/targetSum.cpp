#include <iostream>
#include <climits>
using namespace std;

pair<int, int> findPair(int arr[], int size, int target)
{
  pair<int, int> result;
   int i = 0;
   int j = size-1;
   unsigned int nearest = UINT_MAX;
   unsigned int diff = UINT_MAX;

   sort(arr, (arr + size));
   
   while(i < j)
   {  
     while((arr[i]+arr[j] <= target) && (i < j))
     {
       diff = abs(target - (arr[i] + arr[j]));
     
       if(diff < nearest)
       {
         result.first = arr[i];
         result.second = arr[j];
         nearest = diff;
       }	     
       if(diff == 0)
       {
         return result;
       }
       i++;
     } 
     while((arr[i] + arr[j] >= target) && (i < j))
     {
       diff = abs(target - (arr[i] + arr[j]));
       if(diff < nearest)
       {
         result.first = arr[i];
         result.second = arr[j];
         nearest = diff;
       }
       if(diff == 0)
       {
         return result;
       }
       j--;
     }
  }

return result;
}

int main()
{
  int arr[] = {1, 4, 45, 6, 10, -8};
  int target = 16;
  int size = sizeof(arr)/sizeof(*arr);
  pair<int, int> val;

  val = findPair(arr, size, target);

  cout << val.first << endl;
  cout << val.second << endl;

  return 0;
}
