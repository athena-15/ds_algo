#include <iostream>
#include <cstring>

using namespace std;

int isAnagram(char str1[], char str2[])
{

int m = strlen(str1);
int n = strlen(str2);

int arr1[256] = {0};
int arr2[256] = {0};

if(m != n)
  return 0;

for(int i = 0; str1[i] && str2[i]; i++)
{
  arr1[str1[i]]++;
  arr2[str2[i]]++;
}

for(int i= 0; i<256; i++)
  if(arr1[i] != arr2[i])
    return 0;

return 1;
}

int main()
{
char str1[] = "abc";
char str2[] = "cb";

cout << isAnagram(str1, str2) << endl;
return 0;
}
