//
//  Leetcode257_二叉树路径.cpp
//  
//
//  Created by 铨 on 2019/1/20.
//
//

int GetNum(int n)
{
    int ans = 0;
    while (n!=0)
    {
        n/=10;
        ans++;
    }
    return ans;
}

string Getstring(int n)
{
    bool flag = (n>0);
    n = abs(n);
    int c,t = GetNum(n),i=0;
    //cout << t << endl;
    string result = "";
    char temp;
    for (int j = 0;j < t;j++)
    {
        c = n/pow(10,t-1-i);
        temp = c+'0';
        result+=temp;
        n = n - c*pow(10,t-i-1);
        i++;
    }
    if (!flag) result = '-'+result;
    return result;
}

vector<string> re;
void TreePaths(TreeNode* root,string ss = "")
{
    if (root==NULL) return ;
    string s = ss;
    s+=Getstring(root->val);
    
    if (root->left==NULL && root->right==NULL)
    {
        ss+=Getstring(root->val);
        re.push_back(ss);
    }
    if (root->left!=NULL && root->right==NULL)
    {
        s+="->";
        TreePaths(root->left,s);
    }
    if (root->left==NULL && root->right!=NULL)
    {
        s+="->";
        TreePaths(root->right,s);
    }
    if (root->left!=NULL && root->right!=NULL)
    {
        s+="->";
        TreePaths(root->left,s);
        TreePaths(root->right,s);
    }
    return ;
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        re.clear();
        if (root==NULL) return re;
        TreePaths(root);
        return re;
    }
};
