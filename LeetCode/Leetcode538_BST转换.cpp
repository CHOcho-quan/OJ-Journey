//
//  Leetcode538_BST转换.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

void binaryR(TreeNode *root,TreeNode *result)
{
    if (root==NULL) return;
    result->val+=root->val;
    binaryR(root->right,result);
    binaryR(root->left,result);
}

class Solution {
public:
    TreeNode* convertBST(TreeNode* root,int bigger = 0,bool flag = false) {
        if (root==NULL) return NULL;
        TreeNode* result;
        result= new TreeNode(root->val);
        
        binaryR(root->right,result);
        
        if (root->right==NULL) result->right = NULL;
        else
        {
            root->right->val = bigger*flag + root->right->val;
            result->right = convertBST(root->right,bigger,flag);
        }
        bigger = result->val;
        if (root->left!=NULL)
        {
            root->left->val = bigger + root->left->val;
            flag = true;
            result->left = convertBST(root->left,bigger,flag);
        }
        else result->left = NULL;
        
        return result;    
    }
};
