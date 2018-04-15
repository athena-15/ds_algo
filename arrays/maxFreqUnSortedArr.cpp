#include <iostream>
#include <unordered_map>

using namespace std;

int findMaxFreqElem(int *arr, int len)
{
  unordered_map<int, int> myMap;
  unordered_map<int, int>::iterator itr;

  for(int i = 0; i<len; i++)
  {
    itr = myMap.find(arr[i]);
    if(itr != myMap.end()) //elem is already in the map
    {
      myMap[arr[i]] = itr->second + 1; //increment the count
    }
    else //insert elem into map
    {
      myMap.insert(pair<int, int>(arr[i], 1));
    }
  }
  int max = 0;
  int maxElem = -1;  
  for(itr = myMap.begin(); itr!=myMap.end(); itr++)
  {
    if(itr->second > max)
    {
      max = itr->second;
      maxElem = itr->first;
    }
  }

  return maxElem;
  //return max;
}

int main()
{
  int arr[] = {3, 1, 4, 5, 1, 1, 3};
  int len = sizeof(arr)/sizeof(*arr);

  int ans = findMaxFreqElem(arr, len);

  printf("\n Max freq: %d \n", ans);

return 0;
}
