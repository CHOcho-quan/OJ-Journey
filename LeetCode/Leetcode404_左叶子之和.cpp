/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result = 0;
    
    void recurSum(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr &&
            root->left->left == nullptr &&
            root->left->right == nullptr) {
            result += root->left->val;
        }
        recurSum(root->left);
        recurSum(root->right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        recurSum(root);
        return result;
    }
};
