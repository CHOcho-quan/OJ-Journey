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
    /*
     func : findUST
     if !root->left && !root->right
     ++res
     if root->left || root->right
     l = findUST(root->left)
     if (root->val != l) return -1001;
     */
    
    int result = 0;
    
    int findUST(TreeNode* root) {
        if (!root->left && !root->right) {
            ++result;
            return root->val;
        } else if (!root->left) {
            int r = findUST(root->right);
            if (r != root->val) return -1001;
            ++result;
            return r;
        } else if (!root->right) {
            int l = findUST(root->left);
            if (l != root->val) return -1001;
            ++result;
            return l;
        } else {
            int l = findUST(root->left);
            int r = findUST(root->right);
            if (l != root->val || r != root->val) return -1001;
            ++result;
            return l;
        }
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        findUST(root);
        return result;
    }
};
