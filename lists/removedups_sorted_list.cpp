#include <iostream>

using namespace std;


ListNode*  remove_dups(ListNode *head)
{
ListNode *curr = head;

if(!curr)
  return;

while(curr->next)
{
  if(curr->val == curr->next->val) //duplicate found
  {
    ListNode *node = curr->next->next;
    free(curr->next);
    curr->next = node;
  }
  else //no duplicate
  {
    curr = curr->next;
  }
}
return head;
}

int main()
{

remove_dups(ListNode *head);

}
