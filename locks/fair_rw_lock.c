#include <stdio.h>

typedef struct lock_queue_node_t
{
    int type;
    struct lock_queue_node_t *next;
}lock_queue_node_t;

typedef struct lock_q_t
{
    lock_queue_node_t *head;  
}lock_q_t;


typedef struct rwlock_t
{
    int state; //state of lock : READ/WRITE/UNLOCKED
    int num_lock;
    mutex_t mtx;
    cond_t cv;
    
    lock_q_t q; // memory of struct lock_q_t is allocated
}

void rwlock_init()
{
    mutex_init(&rw->mtx);
    cond_init(&rw->cv);

    //Init the head node of queue to NULL
    rw->q.head = NULL;
    rw->num_lock = 0;
    rw->state = UNLOCKED;    
}

void rwlock_lock(rwlock_t *rw, int type)
{
    lock_queue_node lock_type;
    
    mutex_lock(&rw->mtx); 
 
    //Conditions where u have to add the requesting thread to queue
    if(rw->q.head != NULL || 
       type == READ && rw->state == WRITE ||
       type == WRITE && rw->state != UNLOCKED )
    {
        lock_type.type = type;
                
        enqu(rw->q, &lock_type);
        cond_wait(&rw->cv, &rw->mtx); //wait here unitl woken up
        
        if(type==READ && rw->q.head->type == READ)
        {
          num_lock++;
          deque(rw->q);
          cond_signal(&rw->cv);
        }
    }
    else //no one waiting in the queue
    {
        mutex_lock(&rw->mtx);
        assert(!(rw->state == UNLOCKED && rw->num_lock != 0))
        
        rw->num_lock++;
        rw->state = type;
        mutex_unlock(&rw->mtx);
    }
}

void rwlock_unlock(rwlock_t *rw)
{
    mutex_lock(&rw->mtx);
    rw->num_lock--;
    
    if(rw->num_lock == 0) //if all have given up lock
    {
        if(rw->q.head != NULL) //only writer can be on queue
        {
          rw->state = rw->q.head->type; //change state of lock from read to write
          deque(rw->q); //dequeue the writer
          cond_signal(&rw->cv); //wake up writer
        }
       else //if no one on queue, lock should be unlocked
       {
           rw->state = UNLOCKED;
       }
    }
   mutex_unlock(&rw->mtx);
}             

}
