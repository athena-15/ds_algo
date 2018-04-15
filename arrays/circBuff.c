#include <stdio.h>


typedef struct circBuff
{
  int arr[SIZE];
  int read_idx;
  int write_idx;
}circBuff;

circBuff buff;

int write(circBuff *b)
{

  if( ((b->write_idx + 1)%SIZE) == b->read_idx ) //buffer is full
    return -1;

  b->arr[write_idx] = item;
  b->write_idx = (b->write_idx + 1)%SIZE;
  return 0;
}

int read(circBuff *b)
{
  
  if(b->read_idx == b->write_idx)
  {
    return -1;
  }

  int val = b->arr[b->read_idx];

  b->read_idx = (b->read_idx + 1) % SIZE;
  return 0;
}


int main()
{
circBuff *b;

write(b);
read();

return 0;
}
