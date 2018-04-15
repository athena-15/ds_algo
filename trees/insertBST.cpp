#include <iostream>

using namespace std;

typedef struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
}TreeNode;


TreeNode *insert(TreeNode *root, int value)
{

if(root == NULL) //empty BST
{
  root->data = value;
  root->left = NULL;
  root->right = NULL;

  return root;
}

else if(value < root->data) //BST exists; val<root so go left
{
  root->left = insert(root->left, value);
}
else if(value > root->data)
{
  root->right = insert(root->right, value);
}

return root;
}

int main()
{
TreeNode *root = new TreeNode();
int value = 5;
cout << hex << &root;
insert(root, value);

return 0;
}
