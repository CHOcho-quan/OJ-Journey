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
    TreeNode* buildBST(vector<int>& nums, int st, int en) {
        if (st > en) return nullptr;
        int mid = st + (en - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBST(nums, st, mid - 1);
        root->right = buildBST(nums, mid + 1, en);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return buildBST(nums, l, r);
    }
};
