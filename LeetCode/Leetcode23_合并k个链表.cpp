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
    struct cmp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return (l1->val > l2->val);
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto& l : lists) {
            if (l != nullptr)
                pq.push(l);
        }
        
        ListNode* head = new ListNode(0), *n = head;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            n->next = new ListNode(cur->val);
            n = n->next;
            if (cur->next != nullptr)
                pq.push(cur->next);
        }
        return head->next;
    }
};
