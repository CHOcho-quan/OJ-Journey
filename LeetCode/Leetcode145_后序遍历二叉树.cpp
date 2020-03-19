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
void postorder(TreeNode *root)
{
    if (root->left != NULL) postorder(root->left);
    if (root->right != NULL) postorder(root->left);
    re.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) 
{
    if (root == NULL) return re;
    postorder(root);
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
