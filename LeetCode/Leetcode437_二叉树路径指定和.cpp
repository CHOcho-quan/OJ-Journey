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
    void helper(TreeNode* root, int targetSum, vector<int>& cur, int& pathSum) {
        if (root == nullptr) return;
        for (auto& n : cur) {
            if (root->val == n) ++pathSum;
            n -= root->val;
        }
        cur.push_back(targetSum);
        helper(root->left, targetSum, cur, pathSum);
        helper(root->right, targetSum, cur, pathSum);
        cur.pop_back();
        for (auto& n : cur) {
            n += root->val;
        }
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> cur = {targetSum};
        int result = 0;
        helper(root, targetSum, cur, result);
        return result;
    }
};
