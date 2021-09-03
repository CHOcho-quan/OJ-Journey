/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> check;
        while (headA != nullptr || headB != nullptr) {
            if (headA != nullptr) {
                ++check[headA];
                if (check[headA] > 1) return headA;
                headA = headA->next;
            }
            if (headB != nullptr) {
                ++check[headB];
                if (check[headB] > 1) return headB;
                headB = headB->next;
            }
        }
        
        return nullptr;
    }
};
