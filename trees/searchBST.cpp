#include <iostream>

using namespace std;

typedef struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
}TreeNode;


TreeNode *search(TreeNode *root, int key)
{
  if(root==NULL || root->data == key)
  {
    return root;
  }
  else if(key < root->data)
  {
    return search(root->left, key);    
  }
  else if(key > root->data)
  {
    return search(root->right, key);
  }

}

int main()
{

TreeNode *root = new TreeNode();

int key = 7;

search(root, key);

return 0;
}
