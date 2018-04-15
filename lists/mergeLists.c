#include <stdio.h>

typedef struct ListNode
{
  int data;
  struct ListNode *next;
}ListNode;


ListNode *merge(ListNode *head1, ListNode *head2)
{
  ListNode *headMerged = NULL;

  if(head1 == NULL)
    return head2;
  if(head2 == NULL)
    return head1;

  if(head1->data < head2->data)
  {
    headMerged = head1;
    headMerged->next = merge(head1->next, head2);
  }
  else
  {
    headMerged = head2;
    headMerged->next = merge(head1, head2->next);
  }
return headMerged;
}

int main()
{

ListNode *head1 = NULL;
ListNode *head2 = NULL;

merge(head1, head2);

}
