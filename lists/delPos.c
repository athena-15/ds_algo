#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
  int data;
  struct ListNode *next;
}ListNode;



void delPos(ListNode **head, int pos)
{
  ListNode *temp = *head;
  ListNode *nextnode;

  if(*head == NULL)
    return;
  
  if(pos == 0) \\first node
  {
    *head = temp->next;
     free(temp);
     temp = temp->next;
     return;
  } 
  
  for(int i=0; (i<position-1 && temp!=NULL); i++)
  {
    temp = temp->next;
  }

  if(temp==NULL || temp->next == NULL)
    return;

  nextnode = temp->next->next;
  free(temp->next);
  temp->next = nextnode;
  return;
}



int main()
{

delPos(&head, 2);
return 0;
}


