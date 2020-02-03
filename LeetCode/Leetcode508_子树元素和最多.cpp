#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getFrequentTreeSum(TreeNode* root, vector<int> &ans) {
    if (root == NULL) return {};
    
    if (root->left != NULL and root->right != NULL)
    {
        int re = root->val + getFrequentTreeSum(root->left, ans) + getFrequentTreeSum(root->right, ans);
        ans.push_back(re);
        return re;
    }
    else if (root->left != NULL and root->right == NULL)
    {
        int re = root->val + getFrequentTreeSum(root->left, ans);
        ans.push_back(re);
        return re;
    }
    else if (root->right != NULL and root->left == NULL)
    {
        int re = root->val + getFrequentTreeSum(root->right, ans);
        ans.push_back(re);
        return re;
    }
    else 
    {
        int re = root->val;
        ans.push_back(re);
        return re;
    }
    
    return -1;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;
    getFrequentTreeSum(root, ans);
    
    vector<int> cnt, re;
    for (int i = 0;i < ans.size();i++) cnt.push_back(count(ans.begin(), ans.end(), ans[i]));
    int max_ele = *max_element(cnt.begin(),cnt.end()), maxPosition = max_element(cnt.begin(),cnt.end()) - cnt.begin();
    // cout << max_ele<<endl;
    if (max_ele == 1) return ans;
    else
    {
        for (int i = 0;i < cnt.size();i++)
        {
            if (cnt[i] == max_ele)
            {
                bool flag = false;
                for (int j = 0;j < re.size();j++) if (re[j] == ans[i]) flag = true;
                if (!flag) re.push_back(ans[i]);
            }
        }

        return re;
    }
    return ans;
}

int main()
{
    TreeNode *r;
    r = new TreeNode(5);
    r->left = new TreeNode(2);
    r->right = new TreeNode(-3);

    vector<int> ans = findFrequentTreeSum(r);
    for (int i = 0;i < ans.size();i++) cout << ans[i] << ' ';
}