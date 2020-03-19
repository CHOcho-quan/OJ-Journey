#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) 
{
    if (root == NULL) return 0;
    int layer_num = 1, result = -1;
    queue<TreeNode*> q;
    root->val = 0;
    q.push(root);
    int lfl = 0;

    while(!q.empty())
    {
        int next_layer_num = 0, first_nonnull = 2147483647, last_nonnull = -1;
        for (int i = 0;i < layer_num;i++) {
            TreeNode *tmp = q.front();

            first_nonnull = min(tmp->val, first_nonnull);
            last_nonnull = max(tmp->val, last_nonnull);
            
            if (tmp->left != NULL) {
                if (next_layer_num == 0) lfl = 2 * tmp->val;
                tmp->left->val = tmp->val - lfl + tmp->val;
                q.push(tmp->left);
                next_layer_num++;
            }
            if (tmp->right != NULL) {
                if (next_layer_num == 0) lfl = 2 * tmp->val + 1;
                tmp->right->val = tmp->val - lfl + tmp->val + 1;
                cout << tmp->right->val << endl;
                q.push(tmp->right);
                next_layer_num++;
            }
            
            q.pop();
        }

        result = max(result, 1 + last_nonnull - first_nonnull);
        layer_num = next_layer_num;
    }

    return result;
}

int main()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);

    cout << widthOfBinaryTree(root);
}