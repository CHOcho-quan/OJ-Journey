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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode* slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr) return false;
            else if (fast->next != nullptr && fast->next->next != nullptr)
                fast = fast->next->next;
            else return false;
            slow = slow->next;
        }
        return true;
    }
    
    bool hasCycle1(ListNode *head) {
        if (head == nullptr) return false;
        unordered_set<ListNode*> check;
        
        while (head != nullptr) {
            if (check.count(head)) break;
            check.insert(head);
            if (head->next != nullptr) head = head->next;
            else return false;
        }
        return true;
    }
};
