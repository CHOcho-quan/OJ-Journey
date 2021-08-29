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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l1 = head, *l2 = head, *l1f = nullptr;
        n--;
        while (n--) l2 = l2->next;
        while (l2->next != nullptr) {
            l1f = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        // now delete l1
        if (l1f == nullptr) return head->next;
        l1f->next = l1f->next->next;
        l1->next = nullptr;
        return head;
    }
};
