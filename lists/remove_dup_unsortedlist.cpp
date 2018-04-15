#include <iostream>

using namespace std;


ListNode* remove_dups(ListNode *head)
{
ListNode *ptr1 = head;
ListNode *ptr2 = head;
ListNode *dup;

if(ptr1 == NULL || ptr1->next == NULL)
  return NULL;

while(ptr1 != NULL && ptr1->next != NULL)
{
  ptr2 = ptr1;
  while(ptr2->next)
  {
    if(ptr1->val == ptr2->next->val)
    {
      dup = ptr2->next;
      ptr2->next = ptr2->next->next;
      free(dup);
    }
    else
    {
      ptr2 = ptr2->next;
    }
  }
  ptr1 = ptr1->next;
}
return head;
}


int main()
{

remove_dups(head);

return 0;
}
