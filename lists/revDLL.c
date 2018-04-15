#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
  int data;
  struct ListNode *next;
  struct ListNode *prev;
}ListNode;


void rev(ListNode **head)
{
  ListNode *current = *head;
  ListNode *temp;

  while(current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
   
   current = current->prev;
  }

  if(temp != NULL)
  {
    *head = temp->prev;
  }
}

void printList(ListNode *node)
{
  while(node != NULL)
  {
    printf("\n %d \t", node->data);
    node = node->next;
  }
}

void insert(ListNode **head, int data)
{

ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));

newnode->data = data;
newnode->prev = NULL;
newnode->next = *head;


if(*head != NULL)
{
  (*head)->prev = newnode;
}

*head = newnode; 
}


int main()
{
ListNode *head = NULL;

insert(&head, 1);
insert(&head, 2);
insert(&head, 3);
insert(&head, 4);

printList(head);

rev(&head);

printList(head);

return 0;
}
