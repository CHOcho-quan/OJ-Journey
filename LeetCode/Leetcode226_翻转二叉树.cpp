#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void invertTreeRecur(TreeNode* r)
{
    if (r!=NULL)
    {
        TreeNode *tmp = r->left;
        r->left = r->right;
        r->right = tmp;

        invertTreeRecur(r->left);
        invertTreeRecur(r->right);
    }
}

TreeNode* invertTree(TreeNode* root) 
{
    invertTreeRecur(root);
    return root;
}

int main()
{
    TreeNode *root;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    invertTree(root);
}