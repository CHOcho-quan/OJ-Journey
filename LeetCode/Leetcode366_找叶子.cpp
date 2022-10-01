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
    bool IsLeaf(TreeNode* r) {
        if (!r) return false;
        if (!r->left && !r->right) return true;
        return false;
    }
    
    vector<vector<int>> res;
    
    int getLeaves(TreeNode* root) {
        if (!root) return -1;
        if (IsLeaf(root)) {
            if (res.size() == 0) {
                vector<int> r = {root->val};
                res.push_back(r);
            } else {
                res[0].push_back(root->val);
            }
            return 1;
        } else {
            int ret_level = -1;
            int level = getLeaves(root->left);
            ret_level = max(level, ret_level);
            level = getLeaves(root->right);
            ret_level = max(level, ret_level);
            if (ret_level != -1) {
                if (ret_level >= res.size()) {
                    res.push_back({root->val});
                } else {
                    res[ret_level].push_back(root->val);
                }
            }
            return ret_level + 1;
        }
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        getLeaves(root);
        return res;
    }
};