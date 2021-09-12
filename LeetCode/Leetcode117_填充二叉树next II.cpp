/*
 // Definition for a Node.
 class Node {
 public:
 int val;
 Node* left;
 Node* right;
 Node* next;
 
 Node() : val(0), left(NULL), right(NULL), next(NULL) {}
 
 Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
 
 Node(int _val, Node* _left, Node* _right, Node* _next)
 : val(_val), left(_left), right(_right), next(_next) {}
 };
 */

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        Node* l = nullptr;
        while (!q.empty()) {
            int len = q.size();
            Node* cur = nullptr;
            while (len--) {
                cur = q.front();q.pop();
                if (l) l->next = cur;
                l = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            l = nullptr;
            cur->next = nullptr;
        }
        
        return root;
    }
};
