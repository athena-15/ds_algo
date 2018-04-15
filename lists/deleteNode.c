#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
int data;
struct ListNode *next;
}ListNode;

void append(ListNode **head, int val)
{
ListNode *last = *head;
ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
newnode->data = val;
newnode->next = NULL;

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

return;
}

//DELETE FIRST OCCURRENCE OF THE NODE
void delNode(ListNode **head, int val)
{
ListNode *temp = *head;
ListNode *prev;

//First node is to be deleted
if(temp!= NULL && temp->data == val)
{
  *head = temp->next;
  free(temp);
  return;
}

while(temp!=NULL && temp->data != val)
{
  prev= temp;
  temp = temp->next;
}

if(temp == NULL) //val not present in the list
  return;

if(temp->data == val)
{
  prev->next = temp->next;
  free(temp);
  return;
}
}

//DELETE ALL OCCURRENCES OF THE NODE
void delMultNode(ListNode **head, int val)
{
  ListNode *temp = *head;
  ListNode *prev;

  while(temp!=NULL && temp->data == val)
  {
    *head = temp->next;
     free(temp);
     temp = *head;
  }

  while(temp!=NULL)
  {
    while(temp != NULL && temp->data != val)
    {
      prev = temp;
      temp = temp->next;
    }
 
    if(temp==NULL)
      return;

    if(temp->data == val)
    {
      prev->next = temp->next;
      free(temp);
      temp = temp->next;
    }
  }
return;
}

void printList(ListNode *head)
{
ListNode *temp = head;

while(temp)
{
  printf("\n %d \t", temp->data);
  temp = temp->next;
}

}

int main()
{
ListNode *head = NULL;
append(&head, 1);
append(&head, 2);
append(&head, 3);
append(&head, 3);
append(&head, 4);

//delNode(&head, 2);
//printList(head);

delMultNode(&head, 3);
printList(head);

}
