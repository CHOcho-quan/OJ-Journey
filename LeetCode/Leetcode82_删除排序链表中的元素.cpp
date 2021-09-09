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
        if (!head) return head;
        if (!head->next) return head;
        ListNode* n = head;
        while (n) {
            if (n->val != head->val) break;
            n = n->next;
        }
        if (head->next == n) {
            head->next = deleteDuplicates(n);
            return head;
        } else {
            while (n != head) {
                auto tmp = head->next;
                delete head;
                head = tmp;
            }
            return deleteDuplicates(head);
        }
    }
};
