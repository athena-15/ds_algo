#include <iostream>
using namespace std;
 
int rmdup(int *arr, int len)
{
	int *current;
	int *end = arr + len - 1;
  	int newLen = len;

for(current = arr + 1; arr < end; arr++, current = arr + 1)
{
	while(current <= end)
	{
		if(*current == *arr)
		{
			*current = *end--;
			newLen--;
		}
		else
		{
			current++;
		}
	}
}
return newLen;

}
 
int main() {
	// your code goes here
	int arr[] = {4, 8, 4, 1, 1, 2, 9};
	int len = sizeof(arr)/sizeof(*arr);
 
	int newLen = rmdup(arr, len);
 
	for(int i =0; i<newLen; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}

