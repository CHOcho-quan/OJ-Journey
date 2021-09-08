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
    TreeNode* re;
    bool flag = true;
    TreeNode* recurIBST(TreeNode* root, TreeNode*& pre) {
        if (!root) return root;
        if (!root->left) {
            if (flag) {
                pre = new TreeNode(root->val);
                re = pre;
                flag = false;
            }
        }
        recurIBST(root->left, pre);
        pre->right = new TreeNode(root->val);
        pre = pre->right;
        recurIBST(root->right, pre);
        return root;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        recurIBST(root, pre);
        return re->right;
    }
};
