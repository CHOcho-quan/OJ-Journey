#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCompleteTree(TreeNode* root) 
{
    queue<TreeNode*> q;
    q.push(root);
    bool nullflag = false;

    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();

        if (!nullflag) {
            if ((tmp->left == NULL && tmp->right == NULL) || (tmp->left != NULL && tmp->right == NULL)) {
                nullflag = true;
                if (tmp->left != NULL) q.push(tmp->left);
                continue;
            }

            if (tmp->left == NULL && tmp->right != NULL) return false;
            else {
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        else {
            if (tmp->left != NULL || tmp->right != NULL) return false;
        }
    }

    return true;
}

int main()
{
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(8);
    cout << isCompleteTree(root);
}