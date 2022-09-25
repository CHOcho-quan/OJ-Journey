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
    bool findPath(TreeNode* root, int value, string& path, vector<int>& nodes) {
        if (root->val == value) {
            nodes.push_back(root->val);
            return true;
        }

        if (root->left) {
            path += 'L';
            nodes.push_back(root->left->val);
            if (findPath(root->left, value, path, nodes)) return true;
            path = path.substr(0, path.length() - 1);
            nodes.pop_back();
        }
        if (root->right) {
            path += 'R';
            nodes.push_back(root->right->val);
            if (findPath(root->right, value, path, nodes)) return true;
            path = path.substr(0, path.length() - 1);
            nodes.pop_back();
        }

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        if (!root) return "";

        string p2start, p2dest, res;
        vector<int> nstart = {root->val}, ndest = {root->val};
        findPath(root, startValue, p2start, nstart);
        findPath(root, destValue, p2dest, ndest);

        for (int i = 1; i < min(nstart.size(), ndest.size()); ++i) {
            if (nstart[i] == ndest[i]) {
                p2dest = p2dest.substr(1, p2dest.length());
                p2start = p2start.substr(0, p2start.length() - 1);
            } else break;
        }

        // cout << p2start << ' ' << p2dest << '\n';
        string up(p2start.length(), 'U');
        res = up + p2dest;
        return res;
    }
};