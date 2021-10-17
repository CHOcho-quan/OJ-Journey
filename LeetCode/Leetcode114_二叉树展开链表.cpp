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
    TreeNode* pre = nullptr;
    
    void preorder(TreeNode* root) {
        if (!root) return;
        auto r = root->right;
        auto l = root->left;
        if (pre != nullptr) {
            pre->left = nullptr;
            pre->right = root;
        }
        pre = root;
        preorder(l);
        preorder(r);
    }
    
    void flatten(TreeNode* root) {
        preorder(root);
    }
};
