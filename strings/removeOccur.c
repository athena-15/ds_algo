#include <stdio.h>



void removeOcc(char *s, char c)
{
  char *temp = s;
  
  if(s == NULL)
  return;

  while(*s != '\0')
  {
    if(*temp != c) //not the cshar, so retain
    {
      *temp++ = *s;
    }
    s++;
  }
  *temp = '\0';

}



int main()
{
  char str[] = "Abcd";
  //char *res;

  removeOcc(str, 'b');

  printf("\n %s", str);

 return 0;
}
