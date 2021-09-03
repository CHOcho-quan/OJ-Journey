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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* n = head->next, *re = head;
        while (n != nullptr) {
            if (head->val == n->val) {
                head->next = n->next;
                delete n;
                n = head->next;
            } else {
                head = n;
                n = n->next;
            }
        }
        
        return re;
    }
};
