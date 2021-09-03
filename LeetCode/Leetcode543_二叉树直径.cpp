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
    map<TreeNode*, int> rem;
    
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        if (rem.count(root)) return rem[root];
        rem[root] = max(height(root->left), height(root->right)) + 1;
        return rem[root];
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = height(root->left) + height(root->right);
        result = max(result, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        return result;
    }
};
