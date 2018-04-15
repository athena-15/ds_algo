#include <iostream>


using namespace std;

TreeNode *rev_level_order(TreeNode *root)
{

Queue<TreeNode*> q;
Stack<TreeNode*> s;
TreeNode *node;

q.push(root);

while(!q.empty())
{
  node = q.front();
  q.pop();

  s.push(node);

  if(node->right)
    q.push(node->right);
  if(node->left)
    q.push(node->left);  
}

while(!s.empty())
{
  cout << s.top()->val << endl;
  s.pop();
}

}

void level_order(TreeNode *root)
{
 
  if(!root)
  return;

  while(root)
  {
    cout << root->val;

    if(root->left)
     q.push(root->left);
    if(root->right)
      q.push(root->right);

  root= q.top();
  q.pop();
  }
}

int getHt(TreeNode *root)
{
if(root == NULL)
  return 0;
 
int lht = getHt(root->left);
int rht = getHt(root->right);

if(lht > rht)
 return (lht + 1);
else
 return (rht + 1);

}

void printLevel(TreeNode *root, int level)
{
  if(level == 0)
  return;

  if(level == 1)
    cout << root->val << endl;
  else if(level > 1)
  {
    printLevel(root->left, level-1);
    printLevel(root->right, level-1);
  }
  
}

void printLevelOrder(TreeNode *root)
{

int h = getHt(root);

for(int i = 1; i<=h; i++) //i=h, 
{
  printLevel(root, i);
}
}

}

int main()
{

TreeNode *result = rev_level_order(root);

return 0;
}
