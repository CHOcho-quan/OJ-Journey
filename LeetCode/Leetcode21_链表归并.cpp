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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode* result, *head;
        if (l1->val > l2->val) {
            result = l2;
            head = l2;
            l2 = l2->next;
        } else {
            result = l1;
            head = l1;
            l1 = l1->next;
        }
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                result->next = l2;
                break;
            }
            if (l2 == nullptr) {
                result->next = l1;
                break;
            }
            if (l1->val > l2->val) {
                result->next = l2;
                l2 = l2->next;
                result = result->next;
            } else {
                result->next = l1;
                l1 = l1->next;
                result = result->next;
            }
        }
        return head;
    }
};
