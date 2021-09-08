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
    TreeNode* buildTreeHelper(vector<int>& in, vector<int>& po, int l, int r, int& ro) {
        if (l > r) return nullptr;
        if (ro < 0) return nullptr;
        auto root = new TreeNode(po[ro]);
        int mid = 0;
        for (int i = l; i <= r; ++i) {
            if (po[ro] == in[i]) mid = i;
        }
        root->right = buildTreeHelper(in, po, mid + 1, r, --ro);
        if (!root->right) ++ro;
        root->left = buildTreeHelper(in, po, l, mid - 1, --ro);
        if (!root->left) ++ro;
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ro = inorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, ro, ro);
    }
};
