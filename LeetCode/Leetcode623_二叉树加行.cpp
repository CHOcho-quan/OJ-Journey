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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val, root, nullptr);
            return new_root;
        }

        addRow(root, val, depth, 2);
        return root;
    }

    void addRow(TreeNode* root, int val, int depth, int cur) {
        if (depth == cur) {
            TreeNode* row_left = new TreeNode(val, root->left, nullptr);
            TreeNode* row_right = new TreeNode(val, nullptr, root->right);
            root->left = row_left;
            root->right = row_right;
        } else {
            if (root->left) addRow(root->left, val, depth, cur + 1);
            if (root->right) addRow(root->right, val, depth, cur + 1);
        }
    }
};