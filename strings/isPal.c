#include <stdio.h>
#include <string.h>

int isPal(char str[])
{

int len = strlen(str);
int half = len/2;
int i = 0;

for(i = 0; i<half; i++)
{
  if(str[i] != str[len - 1 -i] )
    return -1;
}
return 0;
}

int  main()
{

char str[] = "aaba";

int val = isPal(str);

printf("\n %d", val);


return 0;
}
