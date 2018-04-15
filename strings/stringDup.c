#include <stdio.h>
#include <stdlib.h>

void removeDup(char *str)
{
  int ip_idx = 1;
  int res_idx = 1;

  while(*(str+ip_idx))
  {
    if(*(str+ip_idx) != *(str+ip_idx-1)) //unique chars
    {
      *(str+res_idx) = *(str+ip_idx);
      res_idx++;		
    }
    ip_idx++;
  }
 *(str+res_idx) = '\0';
}

void removeDup_unsorted(char *str)
{
int ch_arr[256] = {0};
int ip_idx = 0;
int res_idx = 0;

while(*(str+ip_idx))
{
  if(ch_arr[*(str + ip_idx)] == 0) //unique
  {
     ch_arr[*(str+ip_idx)] = 1;
    *(str + res_idx) = *(str + ip_idx);
     res_idx++; 
  }
  ip_idx++;
}
*(str+res_idx) = '\0';
}


int main()
{
char str[] = "eegks";
char str1[] = "geeks";

removeDup(str);
removeDup_unsorted(str1);

printf("\n %s \n", str);
printf("\n %s \n", str1);

return 0;
}
