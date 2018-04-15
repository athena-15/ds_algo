#include <stdio.h>

typedef struct ListNode
{
  int data;
  ListNode *next;
}ListNode;


void insertAtHead(ListNode **head, int data)
{

ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
newnode->data = data;
newnode->next = *head;

*head = newnode;
}

int main()
{

ListNode *head = NULL;;


insertAtHead(&head, data);

}
