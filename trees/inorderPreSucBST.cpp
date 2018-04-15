#include <iostream>

using namespace std;

typedef struct TreeNode
{
int data;
TreeNode *left;
TreeNode *right;
}TreeNode;


TreeNode *findInorderPreSuc(TreeNode *root, TreeNode* &pre, TreeNode* &suc, int key)
{

if(root == NULL)
  return root;

if(root->key == key)
{
  //Inorder pred will be highest val in left subtree
  if(root->left != NULL)
  {
    TreeNode *temp = root->left;
    while(temp->right)
      temp = temp->right;
    pre = temp;
  }
  //Inorder succ will be min value in right subtree
  if(root->right != NULL)
  {
    TreeNode *temp = root->right;
    while(temp->left)
      temp = temp->left;
    suc = temp;
  }
}
else
{
  //if the key is smaller than the root, the root is the successor
  if(key<root->key)
  {
    suc = root;
    findInorderPreSuc(root, pre, suc, key);
  }
  if(key > root->key)
  {
    pre = root;
    findInorderPreSuc(root, pre, suc, key);
  }
}
}

int main()
{
TreeNode *result;
int key = 10;
TreeNode *root = new TreeNode();
TreeNode *pre = NULL;
TreeNode *suc = NULL;

result = findInorderPreSuc(root, pre, suc, key);
return 0;
}
