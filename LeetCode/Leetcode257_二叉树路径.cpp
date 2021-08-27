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
    vector<string> result;
    
    void backtrack(TreeNode* root, string& tmp) {
        if (root->left == nullptr && root->right == nullptr) {
            tmp += to_string(root->val);
            result.push_back(tmp);
            return;
        }
        tmp += to_string(root->val);
        tmp += "->";
        if (root->left != nullptr) {
            int rem = tmp.length();
            backtrack(root->left, tmp);
            tmp.erase(tmp.begin() + rem, tmp.end());
        }
        
        if (root->right != nullptr) {
            int rem = tmp.length();
            backtrack(root->right, tmp);
            tmp.erase(tmp.begin() + rem, tmp.end());
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return result;
        string tmp = "";
        backtrack(root, tmp);
        return result;
    }
};
