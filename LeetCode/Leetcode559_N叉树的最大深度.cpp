#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

int maxDepth(Node* root) 
{
    if (root==NULL) return 0;
    if (root->children.size() == 0) return 1;
    int maxi = 0;
    for (int i = 0;i < root->children.size();i++) maxi = max(maxDepth(root->children[i]), maxi);

    return maxi + 1;
}

int main()
{
    Node *root;
    Node *child1, *child2, *child3;
    vector<Node*> children = {child1, child2, child3};
    root = new Node(1, children);
    child2 = new Node(2);
    child3 = new Node(4);

    Node *child4, *child5;
    child4 = new Node(5);
    child5 = new Node(6);
    vector<Node*> children2 = {child4, child5};
    child1 = new Node(3, children2);

    cout << maxDepth(root);
}