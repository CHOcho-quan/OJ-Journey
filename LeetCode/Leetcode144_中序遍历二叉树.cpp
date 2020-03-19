#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> re;
void preorder(TreeNode *root)
{
    re.push_back(root->val);
    if (root->left != NULL)preorder(root->left);
    if (root->right != NULL)preorder(root->right);
}

vector<int> preorderTraversal(TreeNode* root) 
{
    if (root == NULL) return re;
    preorder(root);
    return re;
}

int main()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);

    cout << postorderTraversal(root);
}