//
//  Leetcode404_左儿子之和.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root,int n = 0) {
        int sum = 0;
        if (root==NULL) return 0;
        if (root->left==NULL && root->right==NULL && n!=0)
        {
            return root->val;
        }
        else if (root->left==NULL && root->right==NULL && n==0) return 0;
        sum+=sumOfLeftLeaves(root->left,1);
        sum+=sumOfLeftLeaves(root->right,0);
        
        return sum;
    }
};
