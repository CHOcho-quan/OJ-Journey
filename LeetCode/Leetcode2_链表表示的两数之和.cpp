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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode* n = l1, *nl = l1;;
        int add = 0;
        while (n != nullptr && l2 != nullptr) {
            n->val += l2->val + add;
            if (n->val >= 10) {
                n->val %= 10;
                add = 1;
            } else add = 0;
            nl = n;
            n = n->next;
            l2 = l2->next;
        }
        if (l2 == nullptr && n == nullptr) {
            if (add) nl->next = new ListNode(1);
            return l1;
        }
        if (n == nullptr) {
            nl->next = l2;
            nl = l2;
            if (!add) return l1;
            while (l2 != nullptr) {
                l2->val += add;
                if (l2->val >= 10) {
                    l2->val %= 10;
                    add = 1;
                } else add = 0;
                nl = l2;
                l2 = l2->next;
            }
            if (add) nl->next = new ListNode(1);
        }
        if (l2 == nullptr) {
            if (!add) return l1;
            while (n != nullptr) {
                n->val += add;
                if (n->val >= 10) {
                    n->val %= 10;
                    add = 1;
                } else add = 0;
                nl = n;
                n = n->next;
            }
            if (add) nl->next = new ListNode(1);
        }
        
        return l1;
    }
};
