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
    unordered_set<int> check;
    
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (findTarget(root->left, k)) return true;
        // cout << "Inserting " << root->val << '\n';
        // cout << check.count(k - root->val) << ' ' << k - root->val << '\n';
        if (check.count(k - root->val)) return true;
        check.insert(root->val);
        if (findTarget(root->right, k)) return true;
        return false;
    }
};
