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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result, rem;
        while (head != nullptr) {
            rem.push_back(head);
            head = head->next;
        }
        int n = rem.size(), ea = n / k, ex = n % k;
        if (ea == 0) {
            result = rem;
            for (int i = 0; i < n; ++i) rem[i]->next = nullptr;
            for (int i = 0; i < k - n; ++i) result.push_back(nullptr);
            return result;
        }
        
        // cout << ea << ' ' << ex << '\n';
        for (int i = ea + (ex != 0); i <= n; i += ea + (ex!=0)) {
            int cur_len = ea + (ex != 0);
            if (ex != 0) --ex;
            rem[i - 1]->next = nullptr;
            result.push_back(rem[i - cur_len]);
        }
        
        return result;
    }
};
