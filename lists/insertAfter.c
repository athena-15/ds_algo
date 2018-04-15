#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
int data;
struct ListNode *next;
}ListNode;

void append(ListNode **head, int val)
{
ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
newnode->data = val;
newnode->next = NULL;

ListNode *last = *head;

if(*head == NULL)//empty list
{
  newnode->next = *head;
  *head = newnode;
  return;
}

while(last->next != NULL)
{
  last = last->next;
}

last->next = newnode;
last = newnode;
}


void insertAfter(ListNode *prev, int val)
{
ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
newnode->data = val;
newnode->next = NULL;

if(prev == NULL)
{
  return;
}

newnode->next = prev->next;
prev->next = newnode;

return;
}

void printList(ListNode *head)
{
ListNode *temp = head;

while(temp!=NULL)
{
  printf("\n %d \t",temp->data);
  temp = temp->next; 
}

}
int main()
{

ListNode *head = NULL;

append(&head,4); //adds to end of list
append(&head, 8);

insertAfter(head, 16);

printList(head);
}



