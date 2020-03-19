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

vector<int> re;
vector<int> postorder(Node* root) 
{
     for (int i = 0;i < root->children.size();i++)
     {
         postorder(root->children[i]);
     }
     cout << root->val;
     return re.push_back(root->val);
}

int main()
{
    //hello world
}