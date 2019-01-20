//
//  Leetcode110_平衡二叉树.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int sumOfTree(TreeNode* root,int sum = 1)
{
    if (root==NULL) return 1;
    if (root->left==NULL && root->right==NULL) return ++sum;
    if (root->left!=NULL && root->right==NULL)
    {
        sum++;
        return sumOfTree(root->left,sum);
    }
    if (root->left==NULL && root->right!=NULL)
    {
        sum++;
        return sumOfTree(root->right,sum);
    }
    if (root->left!=NULL && root->right!=NULL)
    {
        ++sum;
        return max(sumOfTree(root->right,sum),sumOfTree(root->left,sum));
    }
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;
        return (abs(sumOfTree(root->left)-sumOfTree(root->right))<=1) && isBalanced(root->left) && isBalanced(root->right);
    }
};
