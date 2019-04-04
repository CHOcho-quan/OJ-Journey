//
//  SJTU1042_左儿子右兄弟遍历.cpp
//  
//
//  Created by 铨 on 2019/4/1.
//
//

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() {}
    Node(int d, Node * l = NULL, Node * r = NULL) {
        data = d;
        left = l;
        right = r;
    }
};

int main()
{
    Node **tree;
    int n, t0, t1, t2;
    cin >> n;
    tree = new Node*[n+1];
    for (int i = 0;i < n+1;i++) tree[i] = new Node(i);
    int total = n * (n+1) / 2;
    
    for (int i = 1;i < n+1;i++)
    {
        cin >> t0 >> t1 >> t2;
        if (t1!=0) {
            tree[t0]->left = tree[t1];
            total -= t1;
        }
        if (t2!=0) {
            tree[t0]->right = tree[t2];
            total -= t2;
        }
    }
    
    Node *root = tree[total];
    stack<Node *> st;
    
    // pre-order
    st.push(root);
    while (!st.empty())
    {
        Node *tmp = st.top();
        st.pop();
        cout << tmp->data << ' ';
        if (tmp->right!=NULL) st.push(tmp->right);
        if (tmp->left!=NULL) st.push(tmp->left);
    }
    cout << endl;
    
    st.push(root);
    stack<int> cnt;
    cnt.push((root->right!=NULL) + (root->left!=NULL));
    while (!st.empty())
    {
        Node *tmp = st.top();
        int count = cnt.top();
        cnt.pop();
        cnt.push(0);
        if (count == 0)
        {
            cout << tmp->data << ' ';
            tmp = NULL;
            st.pop();
            cnt.pop();
            continue;
        }
        if (tmp->right!=NULL) {
            st.pop();
            cnt.pop();
            st.push(tmp->right);
            st.push(tmp);
            cnt.push((tmp->right->left!=NULL) + (tmp->right->right!=NULL));
            cnt.push(0);
        }
        if (tmp->left!=NULL) {
            st.push(tmp->left);
            cnt.push((tmp->left->left!=NULL) + (tmp->left->right!=NULL));
        }
    }
    cout << endl;
    
    queue<Node *> q1;
    queue<Node *> q2;
    int tt = 0;
    q2.push(root);
    while (!q1.empty() || !q2.empty())
    {
        if (tt)
        {
            while (!q1.empty())
            {
                Node *tmp = q1.front();
                q1.pop();
                while (tmp!=NULL) {
                    q2.push(tmp);
                    tmp = tmp->right;
                }
            }
            tt = 0;
        }
        else {
            while (!q2.empty())
            {
                Node *tmp = q2.front();
                q2.pop();
                q1.push(tmp->left);
                cout << tmp->data << ' ';
            }
            tt = 1;
        }
    }
}
