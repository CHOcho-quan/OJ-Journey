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
    void swapPairDeep(ListNode* last, ListNode* cur) {
        if (cur == nullptr) return;
        auto tmp = cur->next;
        if (tmp == nullptr) return;
        last->next = tmp;
        cur->next = tmp->next;
        tmp->next = cur;
        swapPairDeep(cur, cur->next);
    }
    
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        auto n = head->next;
        if (n == nullptr) return head;
        head->next = n->next;
        n->next = head;
        swapPairDeep(head, head->next);
        return n;
    }
};
