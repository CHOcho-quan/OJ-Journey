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
    TreeNode* buildHelper(vector<int>& pre, vector<int>& po, int l, int r, int& ro) {
        if (l > r) return nullptr;
        if (l == r) {
            auto root = new TreeNode(pre[ro]);
            return root;
        }
        if (ro == pre.size() - 1) {
            auto root = new TreeNode(pre[ro]);
            return root;
        }
        // cout << l << ' ' << r << ' ' << ro << '\n';
        auto root = new TreeNode(pre[ro]);
        int le = pre[ro + 1], mid = 0;
        for (int i = l; i <= r; ++i) {
            if (po[i] == le) mid = i;
        }
        root->left = buildHelper(pre, po, l, mid, ++ro);
        if (!root->left) --ro;
        // cout << ro << ' ' << mid << ' ' << l << '\n';
        if (mid+1 == r) return root;
        
        ++ro;
        // cout << ro << '\n';
        root->right = buildHelper(pre, po, mid + 1, r - 1, ro);
        
        // root->right = buildHelper(pre, po, l, r, ro);
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int ro = 0;
        return buildHelper(preorder, postorder, 0, preorder.size() - 1, ro);
    }
};
