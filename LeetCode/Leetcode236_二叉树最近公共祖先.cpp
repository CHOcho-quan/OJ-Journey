#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *result;
int findTreeNode(TreeNode *root, int p, int q)
{
    if (root == NULL) return 0;
    if (root->val == p) {
        int left = findTreeNode(root->left, p, q), right = findTreeNode(root->right, p, q);
        if (left == 2 || right == 2) {
            result = root;
            return -1000;
        }
        return 1;
    }
    if (root->val == q) {
        int left = findTreeNode(root->left, p, q), right = findTreeNode(root->right, p, q);
        if (left == 1 || right == 1) {
            result = root;
            return -1000;
        }
        return 2;
    }
    int left = findTreeNode(root->left, p, q), right = findTreeNode(root->right, p, q);
    if (left + right == 3) {
        result = root;
        return -1000;
    }

    return left + right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    findTreeNode(root, p->val, q->val);
    return result;       
}

int main()
{
    string s = "abc", t = "cda";
    cout << CheckPermutation(s, t);
}