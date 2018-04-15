#include <iostream>
#include <cstring>

using namespace std;

void rev(char *start, char *end)
{
char temp;


while(start < end)
{
  temp = *start;
  *start = *end;
  *end = temp;

  start++;
  end--;  
}

}

void revWords(char str[])
{

char *start = str;
char *temp = str;


while(*temp)
{
  temp++;

  if(*temp == '\0')
  {
    rev(start, temp-1);
  }
  else if(*temp == ' ')
  {
    rev(start, temp - 1);
    start = temp + 1;
  }
}

//reverse full string
rev(str, temp - 1);
}

int main()
{
//char str[] = "Hello world";
char str[] = "";
int len = strlen(str);
cout << str << endl;

revWords(str);

cout << str << endl;
return 0;
}
