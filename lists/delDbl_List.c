#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
  int data;
  struct ListNode *prev;
  struct ListNode *next;
}ListNode;


void delNode(ListNode **head, ListNode *del)
{

  if(*head == NULL)
    return;

  if(del == *head) //del first node
  {
    *head = del->next;
  }

  if(del->next != NULL)
  {
    del->next->prev = del->prev;
  }

  if(del->prev != NULL)
  {
    del->prev->next = del->next;
  }
  
  free(del);
}

void insert(ListNode **head, int data)
{
  ListNode *newnode = (ListNode *)(malloc(sizeof(ListNode)));

  newnode->data = data;

  newnode->next = *head;
  newnode->prev = NULL;

  if(*head != NULL)
  {
    (*head)->prev = newnode;
  }
  
  *head = newnode;
}


void printList(ListNode *head)
{
  ListNode *temp = head;

  if(temp == NULL)
    return;

  while(temp)
  {
    printf("\n %d \t", temp->data);
    temp = temp->next;
  }
  
}


int main()
{

ListNode *head = NULL;

insert(&head, 1);
insert(&head, 2);
insert(&head, 3);
insert(&head, 4);

printList(head);
delNode(&head, head->next->next);
printList(head);

return 0;
}
