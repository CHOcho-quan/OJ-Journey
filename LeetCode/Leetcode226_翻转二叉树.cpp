//
//  Leetcode226_翻转二叉树.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *result;
        if (root==NULL) return NULL;
        result = new TreeNode(root->val);
        result->left = invertTree(root->right);
        result->right = invertTree(root->left);
        
        return result;
    }
};
