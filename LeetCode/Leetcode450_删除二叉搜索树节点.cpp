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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val > key) {
            if (!root->left) return root;
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            if (!root->right) return root;
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if (root->left && !root->right) {
                auto tmp = root->left;
                delete root;
                return tmp;
            }
            if (root->right && !root->left) {
                auto tmp = root->right;
                delete root;
                return tmp;
            }
            if (root->left && root->right) {
                auto tmp = root->left;
                while (tmp->right) {
                    tmp = tmp->right;
                }
                root->val = tmp->val;
                root->left = deleteNode(root->left, tmp->val);
                return root;
            }
        }
        return root;
    }
};
