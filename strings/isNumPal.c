#include <stdio.h>



int isNumPal(int num)
{
  int reversed = 0;
  int temp = num;

  while(num > 0)
  {
    reversed = (reversed * 10) + (num%10);
    num = num / 10;
  }
  if(reversed == temp)
    return 0;
  else
    return -1;
}

int main()
{

int num = 12;

int val = isNumPal(num);
printf("\n %d", val);

return 0;
}
