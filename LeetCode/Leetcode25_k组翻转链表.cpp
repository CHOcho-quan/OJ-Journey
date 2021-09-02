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
    ListNode* re = nullptr;
    ListNode* rem = nullptr;
    ListNode* reverse(ListNode* head, int level, int k) {
        if (level == k || head->next == nullptr) {
            if (head->next == nullptr && level != k) return nullptr;
            re = head;
            rem = re->next;
            return head;
        }
        auto tmp = reverse(head->next, level + 1, k);
        if (tmp == nullptr) return nullptr;
        tmp->next = head;
        head->next = nullptr;
        return head;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* result, *last;
        bool flag = true;
        
        while (head != nullptr) {
            auto tmp = reverse(head, 1, k);
            if (tmp == nullptr) break;
            // cout << tmp->val << ' ' << rem->val << '\n';
            tmp->next = rem;
            if (flag) {
                last = tmp;
                result = re;
                flag = false;
            } else {
                last->next = re;
                last = tmp;
            }
            head = rem;
        }
        return result;
    }
};
