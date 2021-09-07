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
    int recurConvertBST(TreeNode* root, int al) {
        if (root == nullptr) return 0;
        auto l = recurConvertBST(root->right, al);
        root->val += l;
        if (!root->right) root->val += al;
        return root->left != nullptr ? recurConvertBST(root->left, root->val) : root->val;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        recurConvertBST(root, 0);
        return root;
    }
};
