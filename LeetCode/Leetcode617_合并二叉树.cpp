//
//  Leetcode617_合并二叉树.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *result;
        if (!t1) return t2;
        if (!t2) return t1;
        result = new TreeNode(t1->val + t2->val);
        result->left = mergeTrees(t1->left,t2->left);
        result->right = mergeTrees(t1->right,t2->right);
        return result;
    }
};
