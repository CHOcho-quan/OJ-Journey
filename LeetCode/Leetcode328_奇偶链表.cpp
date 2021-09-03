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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* odd = head, *even = head->next, *n = even->next, *es = even;
        
        bool flag = true;
        while (n != nullptr) {
            if (flag) {
                odd->next = n;
                odd = n;
                n = n->next;
                flag = false;
            } else {
                even->next = n;
                even = n;
                n = n->next;
                flag = true;
            }
        }
        even->next = nullptr;
        odd->next = es;
        return head;
    }
};
