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
    vector<TreeNode*> result;
    set<int> check;
    
    void delNodesRecur(TreeNode* l, TreeNode* root, bool flag, bool lr) {
        if (check.count(root->val)) {
            if (l == nullptr) {
                if (root->left != nullptr) delNodesRecur(nullptr, root->left, true, true);
                if (root->right != nullptr) delNodesRecur(nullptr, root->right, true, false);
                root->left = nullptr;
                root->right = nullptr;
                return;
            }
            if (lr) l->left = nullptr;
            else l->right = nullptr;
            if (root->left != nullptr) delNodesRecur(root, root->left, true, true);
            if (root->right != nullptr) delNodesRecur(root, root->right, true, false);
        } else {
            if (flag) result.push_back(root);
            if (root->left != nullptr) delNodesRecur(root, root->left, false, true);
            if (root->right != nullptr) delNodesRecur(root, root->right, false, false);
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) return result;
        check = set<int>(to_delete.begin(), to_delete.end());
        delNodesRecur(nullptr, root, true, true);
        return result;
    }
};
