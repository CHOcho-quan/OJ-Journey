//
//  Leetcode437_二叉树路径指定和.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int pathSum1(TreeNode* root, int sum,int a = 0,int result = 0)
{
    if (root==NULL) return 0;
    a+=root->val;
    if (a==sum) result++;
    if (root->left==NULL && root->right==NULL) return result;
    if (root->left!=NULL && root->right==NULL) return result+pathSum1(root->left,sum,a,0);
    if (root->left==NULL && root->right!=NULL) return result+pathSum1(root->right,sum,a,0);
    if (root->left!=NULL && root->right!=NULL) return result+pathSum1(root->right,sum,a,0) + pathSum1(root->left,sum,a,0);
}

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root==NULL) return 0;
        return pathSum1(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
