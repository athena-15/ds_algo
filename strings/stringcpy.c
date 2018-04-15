#include <stdio.h>

void stringcpy(char *src, char d[])
{

while(*src != 0)
{
*d++ = *src++;
}

*d = '\0';

}

int main()
{
char *src = "abc";
char dest[5];

stringcpy(src, dest);

printf("\n %s %s \n", src, dest);
return 0;
}
