/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode* sl = head, *fa = head, *bsl = sl;
        while (fa->next && fa->next->next) {
            bsl = sl;
            sl = sl->next;
            fa = fa->next->next;
        }
        if (fa->next) {
            if (bsl != sl) bsl = sl;
            sl = sl->next;
            // bsl = bsl->next;
        }
        TreeNode* root = new TreeNode(sl->val);
        // cout << sl->val << ' ';
        root->right = sortedListToBST(sl->next);
        bsl->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};
