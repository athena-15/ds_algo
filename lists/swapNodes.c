#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
int data;
struct ListNode *next;
}ListNode;


void swapNodes(ListNode **head, int valX, int valY)
{
 
ListNode *pX = NULL;
ListNode *pY = NULL;
ListNode *cX = *head;
ListNode *cY = *head;

if(*head == NULL)
  return;

while(cX != NULL && cX->data != valX)
{  
  pX = cX;
  cX = cX->next;
}

if(cX == NULL)
  return;

while(cY != NULL && cY->data != valY)
{
  pY = cY;
  cY = cY->next;
}

if(cY == NULL)
  return;

if(pX != NULL) //not the head node
{
  pX->next = cY;
}
else
{
*head = cY;
}

if(pY != NULL)
{
  pY->next = cX;
}
else
{
*head = cX;
}

ListNode *temp = cX->next;
cX->next = cY->next;
cY->next = temp;



}

int main()
{

ListNode *head = NULL;

append(&head, 1);
append(&head, 2);
append(&head, 3);
append(&head, 4);
append(&head, 5);


swapNodes(&head, 2, 5);
return 0;
}


