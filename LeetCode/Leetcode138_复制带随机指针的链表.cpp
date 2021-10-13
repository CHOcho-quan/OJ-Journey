/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* next;
 Node* random;
 
 Node(int _val) {
 val = _val;
 next = NULL;
 random = NULL;
 }
 };
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        vector<Node*> ori, res;
        while (head != nullptr) {
            ori.push_back(head);
            auto tmp = new Node(head->val);
            res.push_back(tmp);
            head = head->next;
        }
        
        for (int i = 0; i < ori.size(); ++i) {
            if (i != ori.size() - 1) res[i]->next = res[i + 1];
            auto tmp = ori[i]->random;
            if (!tmp) {
                res[i]->random = nullptr;
                continue;
            }
            int ind = 0;
            for (int j = 0; j < ori.size(); ++j) {
                if (ori[j] == tmp) {
                    ind = j;
                    break;
                }
            }
            res[i]->random = res[ind];
        }
        
        return res[0];
    }
};
