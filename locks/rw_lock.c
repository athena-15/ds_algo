#include <stdio.h>

Sem_t service_qu;
Sem_t resource_access;
Sem_t read_cnt_access;

int read_cnt=0;


void read_lock()
{

  service_qu.P(); //add self to queue to maintain order of service
  
  read_cnt_access.P(); //req excl access to read cnt
  if(read_cnt == 0) //if no readers yet, req excl acceess to resource
  {
    resource_access.P();
  }
  read_cnt++;

  service_qu.V();
  read_cnt_access.V();
  
  //Critcal Section
   read();
  
  read_cnt_access.P();
  read_cnt--;
  if(read_cnt == 0)
  {
    resource_access.V(); //if no more readers, release the lock on resource
  }
  read_cnt_access.V();
}

void write_lock()
{

  service_qu.P(); //add self to queue
  resource_access.P(); //req excl access to shared resource

  service_qu.V();

  //Critical Section
    write();

  resource_access.V(); //release the lock after writer finishes
}



int main()
{

read_lock();

write_lock();

return 0;
}
