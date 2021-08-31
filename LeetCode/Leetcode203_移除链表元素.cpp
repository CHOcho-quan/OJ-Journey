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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) head = head->next;
        if (head == nullptr) return head;
        ListNode* l1 = head, *l2 = head->next;
        
        while (l2 != nullptr) {
            if (l2->val == val) {
                l1->next = l2->next;
                delete l2;
                l2 = l1->next;
            } else {
                l1 = l2;
                l2 = l2->next;
            }
        }
        
        return head;
    }
};
