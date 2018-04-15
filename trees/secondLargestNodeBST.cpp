#include <iostream>

using namespace std;

typedef struct TreeNode
{
int data;
TreeNode *left;
TreeNode *right;
}TreeNode;


void secondLargestUtil(TreeNode *root, int &c)
{

if(root==NULL || c>=2) //base case
  return;

  secondLargestUtil(root->right, c);

  c++;

  if(c==2)
  {
    cout << "Second largest node" << root->data << endl;
    return;
  }

  //No right child, so go to the left child  
  secondLargestUtil(root->left, c);
}

void secondLargest(TreeNode *root)
{
  int c;
  secondLargestUtil(root, c); 
}

int main()
{

TreeNode *root = new TreeNode();

secondLargest(root);
return 0;
}
