#include <iostream>

using namespce std;

typedfe struct TreeNode
{
int data;
TreeNode *left;
TreeNode *right;
}TreeNode;


TreeNode *minValNode(TreeNode *root)
{
  TreeNode *curr = root;

  if(root==NULL)
    return root;

  while(curr->left != NULL)
  {
    curr = curr->left;
  }
  return curr;
}

TreeNode *delNode(TreeNode *root, int val)
{

if(root==NULL)
  return root;

else if(val < root->data)
{
  root->left = delNode(root->left, val);
}

else if(val > root->data)
{
  root->right = delNode(root->right, val);
}

else //at the node to be deleted
{
  if(root->left == NULL)//only 1 child
  {
    TreeNode *temp = new TreeNode();
    temp = root->right;
    delete(root);
    return temp;
  }

  if(root->right == NULL)
  {
    TreeNode *temp = new TreeNode();
    temp = root->left;
    delete(root);
    return temp;
  }

  //have to delete a node which has both children..so find the in order succ
  TreeNode *temp = new TreeNode();
  temp = minValNode(root->right);
  
  root->data = temp->data;

  //go right & delete the inorder succ
  root->right = delNode(root->right, temp->data);
}

return root;
}

int main()
{

delNode(node, val);

return 0;
}
