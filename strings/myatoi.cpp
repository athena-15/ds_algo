#include <iostream>
#include <climits>

#define isNum(x)	(x >= '0' && x <= '9')
#define isSpace(x)	(x == ' ')

using namespace std;


int myatoi(string s)
{
long num = 0;
int i = 0;
int sign = 1;

//skip all the leading spaces
while(isSpace(s[i]))
{
  i++;
}

//encounter first non whitespace char
if(s[i] == '-')
{
  sign = -1;
  i++;
}
else if(s[i] == '+')
{
  sign = 1;
  i++;
}

while(s[i] != '\0')
{
  if(isNum(s[i])) //if its a num
  {
    if(sign == 1)
    {
      if(num*10 + ((s[i] - '0')%10) < INT_MAX)
        num = num*10 + ((s[i] - '0')%10);
      else
      {
        num = INT_MAX;
        break;
      }
    }
    else
    {
      if((num*10 + ((s[i] - '0')%10) - 1) < INT_MAX)
      {
        num = num*10 + ((s[i] - '0')%10);
      }
      else
      {
        num = INT_MAX + 1;
        break;
      }
    }
  }
  else
    break;

  i++;
}
return num*sign;

}

int main()
{
string str = "12345";

cout << myatoi(str) << endl;

return 0;
}
