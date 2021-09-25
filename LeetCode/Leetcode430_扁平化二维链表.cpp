/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* prev;
 Node* next;
 Node* child;
 };
 */

class Solution {
public:
    Node* flattenHelper(Node* head) {
        if (head->next == nullptr && head->child == nullptr) return head;
        if (head->child == nullptr) {
            return flattenHelper(head->next);
        }
        if (head->next == nullptr) {
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
            return flattenHelper(head->next);
        }
        auto tmp = head->next;
        head->next = head->child;
        head->child->prev = head;
        auto cur = flattenHelper(head->child);
        head->child = nullptr;
        cur->next = tmp;
        tmp->prev = cur;
        return flattenHelper(tmp);
    }
    
    Node* flatten(Node* head) {
        if (!head) return head;
        auto result = head;
        flattenHelper(head);
        return result;
    }
};
