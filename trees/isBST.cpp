#include <iostream>

using namespace std;

typedef struct TreeNode
{
int data;
TreeNode *left;
TreeNode *right;
}TreeNode;


int isBSTUtil(TreeNode *root, int min, int max)
{

  if(root == NULL)
  {
    return 1;
  }

    if(root->data<min || root->data > min)
    {
     return 0;
    }
    
    return isBSTUtil(root->left, min, root->data -1) && isBSTUtil(root->right, root->data + 1; max); 

}

int isBST(TreeNode * root)
{

  if(root == NULL)
  {
    return root;
  }

  isBSTUtil(root, INT_MIN, INzT_MAX);
}

int main()
{

TreeNode *root = new TreeNode();

int ans = isBST(root);
return 0;
}
