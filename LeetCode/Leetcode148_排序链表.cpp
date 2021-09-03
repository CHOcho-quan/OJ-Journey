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
    void mergeSort(ListNode* l, ListNode* r) {
        if (l == r) return;
        
        ListNode* slow = l, *fast = l, *mid;
        while (fast != r && fast->next != r) {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
        
        mergeSort(l, mid);
        mergeSort(mid->next, r);
        
        ListNode* n = l, *rem = mid;
        vector<int> c;
        mid = mid->next;
        while (l != rem->next && mid != r->next) {
            if (l->val > mid->val) {
                c.push_back(mid->val);
                // n->val = mid->val;
                mid = mid->next;
            } else {
                c.push_back(l->val);
                l = l->next;
            }
        }
        while (l != rem->next) {
            c.push_back(l->val);
            l = l->next;
        }
        while (mid != r->next) {
            c.push_back(mid->val);
            mid = mid->next;
        }
        for (auto& t : c) {
            // cout << t << ' ';
            n->val = t;
            n = n->next;
        }
        // cout << '\n';
    }
    
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* last = head;
        while (last->next != nullptr) last = last->next;
        mergeSort(head, last);
        return head;
    }
};
