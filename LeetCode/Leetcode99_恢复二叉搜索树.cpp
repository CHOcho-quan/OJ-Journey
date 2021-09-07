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
    pair<TreeNode*, TreeNode*> recurRecover(TreeNode* root, TreeNode* l, TreeNode* r) {
        if (root == nullptr) return pair<TreeNode*, TreeNode*>(nullptr, nullptr);
        if ((l == nullptr || root->val > l->val) && (r == nullptr || root->val <= r->val)) {
            auto x1 = recurRecover(root->left, l, root);
            auto x2 = recurRecover(root->right, root, r);
            if (x1.first != nullptr && x2.first != nullptr) {
                auto tmp = x1.first->val;
                x1.first->val = x2.first->val;
                x2.first->val = tmp;
                return pair<TreeNode*, TreeNode*>(nullptr, nullptr);
            } else if (x1.first != nullptr) {
                if (l == nullptr && r == nullptr) {
                    auto tmp = x1.first->val;
                    x1.first->val = x1.second->val;
                    x1.second->val = tmp;
                    return pair<TreeNode*, TreeNode*>(nullptr, nullptr);
                }
                return x1;
            } else if (x2.first != nullptr) {
                if (l == nullptr && r == nullptr) {
                    auto tmp = x2.first->val;
                    x2.first->val = x2.second->val;
                    x2.second->val = tmp;
                    return pair<TreeNode*, TreeNode*>(nullptr, nullptr);
                }
                return x2;
            }
        } else if (l != nullptr && root->val <= l->val) {
            auto check = recurRecover(root->right, l, r);
            return check.first == nullptr ?
            pair<TreeNode*, TreeNode*>(root, l) : pair<TreeNode*, TreeNode*>(check.first, l);
        } else if (r != nullptr && root->val > r->val) {
            auto check = recurRecover(root->left, l, r);
            return check.first == nullptr ? pair<TreeNode*, TreeNode*>(root, r) : pair<TreeNode*, TreeNode*>(check.first, r);
        }
        return pair<TreeNode*, TreeNode*>(nullptr, nullptr);
    }
    
    void recoverTree(TreeNode* root) {
        recurRecover(root, nullptr, nullptr);
    }
};
