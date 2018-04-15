#include <stdio.h>
 
void *removeOccur(char *str, char c)
{
char *temp = str;
 
 
while(*str)
{
if(*str != c)
*temp++ = *str;
 
str++;
}
 
*temp = '\0';
}
//return temp;
//return *str;

 
int main(void) {
// your code goes here
 
char s[] = "hello";
//char *result = removeOccur(s, 'l');
removeOccur(s, 'l');
printf("\n %s", s);
 
return 0;
}
