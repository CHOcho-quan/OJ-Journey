//
//  Leetcode104_二叉树最深深度.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};
