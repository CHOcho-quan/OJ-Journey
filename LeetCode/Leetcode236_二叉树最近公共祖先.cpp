/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findNode(TreeNode* root, TreeNode* t) {
        if (root == nullptr) return false;
        if (root == t) return true;
        return findNode(root->left, t) || findNode(root->right, t);
    }
    
    TreeNode* re;
    int recurLCA(TreeNode* root, TreeNode* t1, TreeNode* t2) {
        if (root == nullptr) return 0;
        if (root == t1) {
            if (findNode(root, t2)) {
                re = root;
                return 3;
            } else return 1;
        } else if (root == t2) {
            if (findNode(root, t1)) {
                re = root;
                return 3;
            } else return 2;
        }
        int l1 = recurLCA(root->left, t1, t2), l2 = recurLCA(root->right, t1, t2);
        if (l1 == 3 || l2 == 3) return 3;
        if (l1 + l2 == 3) {
            re = root;
            return 3;
        }
        return l1 + l2;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurLCA(root, p, q);
        return re;
    }
};
