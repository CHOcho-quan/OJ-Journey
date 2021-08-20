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
    ListNode* re = NULL;
    
    ListNode * reverseList(ListNode* head) {
        recurseReverseList(head);
        return re;
    }
    
    ListNode * recurseReverseList(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) {
            re = head;
            return head;
        }
        recurseReverseList(head->next)->next = head;
        head->next = NULL;
        return head;
    }
    ListNode* normalReverseList(ListNode* head) {
        if (head == NULL) return NULL;
        stack<ListNode*> st;
        while (head != NULL) {
            st.push(head);
            head = head->next;
        }
        auto now = st.top(), result = now;
        st.pop();
        while (!st.empty()) {
            auto tmp = st.top();
            st.pop();
            now->next = tmp;
            now = tmp;
        }
        now->next = nullptr;
        return result;
    }
};
