/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> help;
        helper(root, help);
        return help;
    }

    void helper(TreeNode* root, vector<int> & help) {
        if (root == NULL) return;
        if (root->left != NULL) helper(root->left, help);
        help.push_back(root->val);
        if (root->right != NULL) helper(root->right, help);
    }
};
