#include <stdio.h>

typedef struct TreeNode
{
struct TreeNode *left;
struct TreeNode *right;
int data;
}TreeNode;


int getHt(TreeNode *root)
{
 int lht, rht, ht;

 if(root == NULL)
   return 1;

 lht = getHt(root->left);
 rht = getHt(root->right);

 if(lht > rht)
  return (1+ max(lht, rht));
}

int isBalanced(TreeNode *root)
{
int 1, r;

l = getHt(root->left);
r = getHt(root->right);

if (abs(l-r) <= 1 && isBalanced(root->left) && isBalanced(root->right) )
{
  return 1;
}

return 0;
}

int main()
{

TreeNode *root = NULL;

isBalanced(root);

return 0;
}
