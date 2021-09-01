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
        if (root == nullptr) return root;
        queue<Node*> q;
        
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            Node* last = q.front();
            while (len--) {
                Node* now = q.front();
                if (now != last)
                    last->next = now;
                last = now;
                q.pop();
                if (now->left != nullptr) {
                    q.push(now->left);
                    q.push(now->right);
                }
            }
            last->next = nullptr;
        }
        
        return root;
    }
};
