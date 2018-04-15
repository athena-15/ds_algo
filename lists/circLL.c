#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
int data;
struct ListNode *next;
}ListNode;



void insert(ListNode **head, int data)
{

ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
ListNode *temp = *head;

newnode->data = data;
newnode->next = *head;

if(*head != NULL)
{
  while(temp->next != *head)
  {
    temp = temp->next;
  }
  temp->next = newnode; 
}
else
{
  newnode->next = newnode; //for the first node
}

*head = newnode;
}

void printList(ListNode *node)
{
  ListNode *temp = node;

  do
  {
    printf("\n %d \t", temp->data);
    temp = temp->next;
  }while(temp != node);
}

int main()
{
ListNode *head = NULL;

insert(&head, 1);
insert(&head, 2);
insert(&head, 3);
insert(&head, 4);
insert(&head, 5);

printList(head);

return 0;
}

