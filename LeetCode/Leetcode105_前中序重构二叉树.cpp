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
    TreeNode* helper(vector<int>& pre, vector<int>& in, int l, int r, int& ro) {
        // cout << l << ' ' << r << ' ' << ro << '\n';
        if (r < l) return nullptr;
        if (ro >= pre.size()) return nullptr;
        TreeNode* root = new TreeNode(pre[ro]);
        int rem = l;
        for (; rem <= r; ++rem) {
            if (in[rem] == root->val) break;
        }
        root->left = helper(pre, in, l, rem - 1, ++ro);
        if (root->left != nullptr) {
            root->right = helper(pre, in, rem + 1, r, ++ro);
            if (!root->right) --ro;
        }
        else {
            root->right = helper(pre, in, rem + 1, r, ro);
            if (!root->right) --ro;
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l = 0;
        return helper(preorder, inorder, 0, preorder.size() - 1, l);
    }
};
