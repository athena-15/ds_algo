#include <iostream>
#include <cstring>

using namespace std;

bool isSubstring(char str1[], char str2[], int m, int n)
{

if(m == 0)
  return true;
if(n ==0)
  return false;

if(str1[m-1] == str2[n-1]) //last characters match
{
  return isSubstring(str1, str2, m-1, n-1);
}
  return isSubstring(str1, str2, m, n-1);
}


int main()
{
char str1[] = "greek";
char str2[] = "geek";

int m = strlen(str1);
int n = strlen(str2);

if(isSubstring(str1, str2, m, n))
{
  cout << "Its a substring" << endl;
}
else
{
  cout << "Not a substring" << endl;
}

return 0;
}
