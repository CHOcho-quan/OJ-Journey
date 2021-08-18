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
    ListNode *detectCycle1(ListNode *head) {
        std::map<ListNode*, int> visit;
        visit[head] = 1;
        while (head != NULL) {
            head = head->next;
            if (visit.count(head)) return head;
            else visit[head] = 1;
        }
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) return NULL;
            fast = fast->next;
            if (slow == fast) break;
        }
        if (fast == NULL) return NULL;
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
