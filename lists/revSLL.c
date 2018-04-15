#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
int data;
struct ListNode *next;
}ListNode;



void append(ListNode **head, int data)
{
  ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
  ListNode *temp = *head;

  newnode->data = data;
  newnode->next = NULL;

  if(*head == NULL)
  {
    *head = newnode;
    return;
  }
 
  while(temp->next != NULL)
  {
    temp=temp->next;
  }
  temp->next = newnode;
}


void printList(ListNode *node)
{
  if(node == NULL)
    return;

  while(node)
  {
    printf("\n %d \t", node->data);
    node = node->next;
  }
}


void revList(ListNode **head)
{
  ListNode *current = *head;
  ListNode *prev = NULL;
  ListNode *next;

  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}


int main()
{
ListNode *head = NULL;

append(&head, 1);
append(&head, 2);
append(&head, 3);
append(&head, 4);

printList(head);

revList(&head);

printList(head);

return 0;
}

